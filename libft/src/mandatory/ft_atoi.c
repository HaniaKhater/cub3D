/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:09:17 by rchan--r          #+#    #+#             */
/*   Updated: 2022/02/05 17:50:08 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	minus;

	res = 0;
	i = 0;
	minus = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = 1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	if (minus == 1)
		return (-res);
	return (res);
}
