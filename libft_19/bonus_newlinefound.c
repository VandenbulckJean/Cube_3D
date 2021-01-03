/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_newlinefound.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:39:05 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/18 15:39:07 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int		newlinefound(char *linebuffer)
{
	int		i;

	i = 0;
	while (linebuffer[i])
	{
		if (linebuffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
