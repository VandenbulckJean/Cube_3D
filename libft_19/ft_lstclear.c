/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:46:56 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/15 09:48:59 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*todelete;

	temp = *lst;
	while (temp)
	{
		todelete = temp;
		del(todelete->content);
		temp = temp->next;
		free(todelete);
	}
	*lst = NULL;
}
