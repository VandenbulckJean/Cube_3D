/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_strjoin_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:39:24 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/18 15:39:26 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*strjoin_front(char *s1, char *s2)
{
	char	*newline;
	char	*temp;
	int		i;

	i = 0;
	if (!(newline = (char*)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	temp = newline;
	while (*s2)
		*temp++ = *s2++;
	while (s1[i])
		*temp++ = s1[i++];
	*temp = '\0';
	free(s1);
	return (newline);
}
