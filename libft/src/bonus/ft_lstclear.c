/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:23:40 by rchan--r          #+#    #+#             */
/*   Updated: 2022/02/12 17:54:16 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)
		ft_lstdelone(*lst, del);
	else
	{
		ft_lstclear(&((*lst)-> next), del);
		ft_lstdelone(*lst, del);
	}
	*lst = NULL;
}
