/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:12:04 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/15 10:58:00 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		*str = '\0';
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[start] && i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
	}
	return (str);
}
