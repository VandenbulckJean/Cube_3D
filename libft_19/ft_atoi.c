/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:09:10 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/13 09:28:32 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	result = 0;
	sign = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] && str[i] == '-')
	{
		sign++;
		i++;
	}
	else if (str[i] && str[i] == '+')
		i++;
	while (ft_isnumber(str[i]) && str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (sign)
		return (-result);
	return (result);
}
