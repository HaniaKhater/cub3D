/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:49:08 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/19 12:45:44 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* does not free in case of error! (helps freeing when extend is called))*/
/*
static int	tab_fill(char ***tab, int size)
{
	int	i;

	if (size < 1)
		return (0);
	i = 0;
	while (i < size)
	{
		(*tab)[i] = malloc(sizeof(char));
		if ((*tab)[i] == NULL)
			return (0);
		(*tab)[i][0] = '\0';
		i++;
	}
	(*tab)[size] = NULL;
	return (1);
}
*/

static void	tab_copy(char **src, char **dst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

static int	tab_extend(char ***tab)
{
	static int	k = 2;
	char		**new;
	char		**tmp;

	new = malloc(sizeof(char *) * (k * TAB_INIT_SIZE + 1));
	if (new == NULL)
	{
		tab_free(tab);
		return (0);
	}
	tab_copy(*tab, new, (k - 1) * TAB_INIT_SIZE);
	tmp = new + (k - 1) * TAB_INIT_SIZE;
	if (tab_fill(&tmp, TAB_INIT_SIZE) == 0)
	{
		tab_free(&new);
		tab_free(tab);
		tab = NULL;
		return (0);
	}
	k++;
	free(*tab);
	*tab = new;
	return (1);
}

int	tab_append(char ***tab, char *str)
{
	static int	next_empty = 0;

	if (tab == NULL)
		return (0);
	if (str == NULL)
		return (tab_free(tab), 0);
	if (*tab == NULL)
	{
		if (tab_init(tab) == 0)
			return (0);
	}
	if ((*tab)[next_empty] == NULL)
	{
		if (tab_extend(tab) == 0)
			return (0);
	}
	free((*tab)[next_empty]);
	(*tab)[next_empty] = str;
	next_empty++;
	return (1);
}
