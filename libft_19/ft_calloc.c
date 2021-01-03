/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:08:30 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/09 11:08:32 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memptr;

	if (!(memptr = (void*)malloc(size * count)))
		return (NULL);
	ft_bzero(memptr, size * count);
	return (memptr);
}
