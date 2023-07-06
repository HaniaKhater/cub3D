/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:17:33 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/18 21:07:47 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	tab_print_debug(char **tab)
{
	int	i;

	if (tab == NULL)
	{
		ft_printf("\n");
		return ;
	}
	if (tab[0] != NULL)
	{
		ft_printf("0: %s", tab[0]);
		i = 1;
		while (tab[i] != NULL)
		{
			ft_printf("  %d: %s", i, tab[i]);
			i++;
		}
		ft_printf("\n");
	}
}*/

void	tab_print(char **tab)
{
	int		i;
	char	*tmp;

	if (tab == NULL)
		return ;
	i = 0;
	tmp = tab[i];
	while (tmp != NULL && ft_strncmp(tmp, "", ft_strlen(tmp) + 1) != 0)
	{
		ft_printf("%s\n", tmp);
		i++;
		tmp = tab[i];
	}
}
