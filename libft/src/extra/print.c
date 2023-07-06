/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:20:40 by rchan--r          #+#    #+#             */
/*   Updated: 2022/05/15 20:11:26 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(size_t l)
{
	if (l <= 9)
	{
		l += 48;
		write(1, &l, 1);
	}
	else
	{
		ft_print_ptr(l / 10);
		ft_print_ptr(l % 10);
	}
}

void	ft_print_ptr_hexa(size_t l)
{
	if (l <= 15)
	{
		if (l < 10)
			ft_print_ptr(l);
		else
		{
			l = l - 10 + 'a';
			write(1, &l, 1);
		}
	}
	else
	{
		ft_print_ptr_hexa(l / 16);
		ft_print_ptr_hexa(l % 16);
	}
}

void	ft_print_nbr_u(unsigned int u)
{
	if (u < 10)
	{
		u += '0';
		write(1, &u, 1);
	}
	else
	{
		ft_print_nbr_u(u / 10);
		ft_print_nbr_u(u % 10);
	}
}

void	ft_print_ptr_upper_hexa(size_t l)
{
	if (l <= 15)
	{
		if (l < 10)
			ft_print_ptr(l);
		else
		{
			l = l - 10 + 'A';
			write(1, &l, 1);
		}
	}
	else
	{
		ft_print_ptr_upper_hexa(l / 16);
		ft_print_ptr_upper_hexa(l % 16);
	}
}
