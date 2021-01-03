/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:08:48 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/09 11:08:50 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1bis;
	size_t	i;

	i = ft_strlen(s1);
	if (!(s1bis = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s1bis[i] = s1[i];
		i++;
	}
	s1bis[i] = '\0';
	return (s1bis);
}
