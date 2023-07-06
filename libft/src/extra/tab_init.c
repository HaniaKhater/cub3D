/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:49:08 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/19 11:30:19 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tab_init(char ***tab)
{
	if (tab == NULL)
		return (0);
	*tab = malloc(sizeof(char *) * (TAB_INIT_SIZE + 1));
	if (*tab == NULL)
		return (0);
	if (tab_fill(tab, TAB_INIT_SIZE) == 0)
	{
		tab_free(tab);
		return (0);
	}
	return (1);
}
