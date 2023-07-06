/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:40:42 by rchan--r          #+#    #+#             */
/*   Updated: 2022/02/10 15:28:52 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		un = -n;
	}
	if (un / 10 == 0)
		ft_putchar_fd(un + '0', fd);
	else
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putnbr_fd(un % 10, fd);
	}
}
