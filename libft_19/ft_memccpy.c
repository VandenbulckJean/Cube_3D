/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:10:31 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/07 14:10:31 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *destination;
	unsigned char *source;

	if (!src && !dst)
		return (NULL);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n--)
	{
		*destination = *source;
		if (*destination == (unsigned char)c)
		{
			destination++;
			return ((void*)destination);
		}
		destination++;
		source++;
	}
	return (NULL);
}
