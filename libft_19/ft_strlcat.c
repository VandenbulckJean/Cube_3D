/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:11:44 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/13 10:00:43 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t total;
	size_t i;

	i = 0;
	while (dst[i] && (i < dstsize))
		i++;
	total = i + ft_strlen(src);
	if (i == dstsize)
		return (total);
	while (*src && i < dstsize - 1)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (total);
}
