/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:34:38 by rchan--r          #+#    #+#             */
/*   Updated: 2022/05/14 00:10:26 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr_hexa(size_t l)
{
	int	res;

	res = 1;
	while (l > 15)
	{
		l /= 16;
		res++;
	}
	return (res);
}

int	ft_len_ptr(size_t l)
{
	int	res;

	res = 1;
	while (l > 9)
	{
		l /= 10;
		res++;
	}
	return (res);
}

int	ft_len_nbr(int n)
{
	unsigned int	tmp;
	int				res;

	res = 1;
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		res++;
	}
	while (tmp > 9)
	{
		tmp /= 10;
		res++;
	}
	return (res);
}

int	ft_len_nbr_u(unsigned int u)
{
	int	res;

	res = 1;
	while (u > 9)
	{
		u /= 10;
		res++;
	}
	return (res);
}
