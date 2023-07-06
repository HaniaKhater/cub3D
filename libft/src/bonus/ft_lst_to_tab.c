/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:02:12 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/20 11:14:13 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_tab(t_list *lst)
{
	char	**res;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	res = malloc(sizeof(void *) * (size + 1));
	if (res == NULL)
		return (NULL);
	res[size] = NULL;
	i = 0;
	while (i < size)
	{
		res[i] = lst->content;
		lst = lst->next;
		i++;
	}
	return (res);
}
