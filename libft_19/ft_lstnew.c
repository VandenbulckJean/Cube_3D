/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 09:50:13 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/12 09:50:15 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_el;

	if (!(new_el = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}
