/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:26:31 by rchan--r          #+#    #+#             */
/*   Updated: 2022/02/12 19:49:44 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinit_res(t_list **ptr_res, t_list **ptr_lst, void *(*f)(void *))
{
	t_list	*tmp2;

	tmp2 = ft_lstnew(f((*ptr_lst)->content));
	if (tmp2 == NULL)
		return ;
	ft_lstadd_back(ptr_res, tmp2);
	*ptr_lst = (*ptr_lst)->next;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst == NULL)
		return (NULL);
	res = NULL;
	ft_lstinit_res(&res, &lst, f);
	if (res == NULL)
		return (NULL);
	tmp1 = res;
	while (lst != NULL)
	{
		tmp2 = ft_lstnew(f(lst->content));
		if (tmp2 == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp1, tmp2);
		tmp1 = tmp2;
		lst = lst->next;
	}
	return (res);
}
