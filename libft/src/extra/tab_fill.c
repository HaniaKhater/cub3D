/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:49:08 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/19 11:30:01 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tab_fill(char ***tab, int size)
{
	int	i;

	if (tab == NULL || *tab == NULL)
		return (0);
	if (size < 1)
		return (0);
	i = 0;
	while (i < size)
	{
		(*tab)[i] = ft_strdup("");
		if ((*tab)[i] == NULL)
			return (0);
		i++;
	}
	(*tab)[size] = NULL;
	return (1);
}
