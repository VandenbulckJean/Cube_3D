/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:39:34 by jvanden-          #+#    #+#             */
/*   Updated: 2021/01/28 13:26:16 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int			is_space(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int			is_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(is_space(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int			check_if_number(char *str, int i)
{
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && str[i] == '-')
		i++;
	if (str[i] && isnumber(str[i]))
		return (0);
	return (1);
}

void		atoi_cube(char *str, int *i, int *result)
{
	int sign;

	*result = 0;
	sign = 0;
	while (str[*i] && is_space(str[*i]))
		(*i)++;
	if (str[(*i)] == '-')
	{
		sign++;
		(*i)++;
	}
	while (isnumber(str[*i]))
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
		if (*result > (INT_MAX / 100))
		{
			while (isnumber(str[*i]))
				(*i)++;
			break ;
		}
	}
	if (sign)
		*result = -(*result);
}
