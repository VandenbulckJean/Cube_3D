/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_strjoin_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:39:18 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/18 15:39:22 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*strjoin_back(char *line, char *buffer)
{
	char	*newline;
	char	*temp;
	int		i;

	i = 0;
	if (!(newline = (char*)malloc(sizeof(char) *
	(ft_strlen(line) + ft_strlen(buffer) + 1))))
		return (NULL);
	temp = newline;
	while (line[i])
		*temp++ = line[i++];
	while (*buffer)
		*temp++ = *buffer++;
	*temp = '\0';
	free(line);
	return (newline);
}
