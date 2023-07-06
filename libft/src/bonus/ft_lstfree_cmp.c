/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:59 by rchan--r          #+#    #+#             */
/*   Updated: 2023/03/25 11:59:22 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nodefree_next(t_list *node)
{
	t_list	*tmp;

	tmp = node->next;
	node->next = node->next->next;
	free(tmp->content);
	free(tmp);
}

void	ft_lstfree_cmp(t_list **lst, void *content, int (*cmp)(void *, void *))
{
	t_list	*node;

	if (lst == NULL || *lst == NULL)
		return ;
	node = *lst;
	if (cmp(node->content, content) == 0)
	{
		*lst = node->next;
		free(node->content);
		free(node);
		node = *lst;
		ft_lstfree_cmp(lst, content, cmp);
		return ;
	}
	while (node->next != NULL)
	{
		while (node->next != NULL && cmp(node->next->content, content) == 0)
			nodefree_next(node);
		if (node->next == NULL)
			return ;
		node = node->next;
	}
}
