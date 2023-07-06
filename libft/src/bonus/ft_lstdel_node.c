/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:32:26 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/20 14:42:21 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_node(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	if (*lst == node)
	{
		*lst = node->next;
		ft_lstdelone(node, del);
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL && tmp->next != node)
		tmp = tmp->next;
	if (tmp->next == node)
	{
		tmp->next = node->next;
		ft_lstdelone(node, del);
		return ;
	}
}
