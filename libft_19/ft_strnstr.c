/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:12:15 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/12 11:36:46 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	position;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			position = i;
			while (needle[j] == haystack[i] && i < len)
			{
				j++;
				i++;
				if (needle[j] == '\0')
					return (&((char*)haystack)[position]);
			}
		}
		else
			i++;
	}
	return (NULL);
}
