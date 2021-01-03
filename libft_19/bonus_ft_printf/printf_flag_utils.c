/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:42 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/17 18:18:45 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_bonus.h"

char	*create_filled_string(int length, char filler)
{
	int		i;
	char	*str;

	i = 0;
	if (length > 0)
	{
		if (!(str = malloc(sizeof(char) * (length + 1))))
			return (NULL);
		while (i < length)
			str[i++] = filler;
		str[length] = '\0';
	}
	else
	{
		if (!(str = malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

int		memory_allocation_error_free(void *to_free)
{
	free(to_free);
	return (-1);
}

char	*truncstr(char *oldstr, int range)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!(newstr = malloc(sizeof(char) * range + 1)))
		return (NULL);
	while (i < range)
	{
		newstr[i] = oldstr[i];
		i++;
	}
	newstr[range] = '\0';
	free(oldstr);
	return (newstr);
}
