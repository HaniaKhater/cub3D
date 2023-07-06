/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:20:40 by rchan--r          #+#    #+#             */
/*   Updated: 2023/03/30 15:27:01 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_fd_ptr(int fd, size_t l)
{
	if (l <= 9)
	{
		l += 48;
		write(fd, &l, 1);
	}
	else
	{
		ft_print_fd_ptr(fd, l / 10);
		ft_print_fd_ptr(fd, l % 10);
	}
}

void	ft_print_fd_ptr_hexa(int fd, size_t l)
{
	if (l <= 15)
	{
		if (l < 10)
			ft_print_fd_ptr(fd, l);
		else
		{
			l = l - 10 + 'a';
			write(fd, &l, 1);
		}
	}
	else
	{
		ft_print_fd_ptr_hexa(fd, l / 16);
		ft_print_fd_ptr_hexa(fd, l % 16);
	}
}

void	ft_print_fd_nbr_u(int fd, unsigned int u)
{
	if (u < 10)
	{
		u += '0';
		write(fd, &u, 1);
	}
	else
	{
		ft_print_fd_nbr_u(fd, u / 10);
		ft_print_fd_nbr_u(fd, u % 10);
	}
}

void	ft_print_fd_ptr_upper_hexa(int fd, size_t l)
{
	if (l <= 15)
	{
		if (l < 10)
			ft_print_fd_ptr(fd, l);
		else
		{
			l = l - 10 + 'A';
			write(fd, &l, 1);
		}
	}
	else
	{
		ft_print_fd_ptr_upper_hexa(fd, l / 16);
		ft_print_fd_ptr_upper_hexa(fd, l % 16);
	}
}
