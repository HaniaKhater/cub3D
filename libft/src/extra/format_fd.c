/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:53:16 by rchan--r          #+#    #+#             */
/*   Updated: 2023/03/30 15:28:41 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	format_fd_c(int fd, va_list ap, int *ptr)
{
	ft_putchar_fd(va_arg(ap, int), fd);
	*ptr += 1;
}

void	format_fd_s(int fd, va_list ap, int *ptr)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		*ptr += ft_strlen(s);
	}
	else
	{
		ft_putstr_fd(STR_NULL, fd);
		*ptr += ft_strlen(STR_NULL);
	}
}

void	format_fd_p(int fd, va_list ap, int *ptr)
{
	size_t	arg;

	arg = va_arg(ap, size_t);
	if (arg != 0)
	{
		write(fd, "0x", 2);
		ft_print_fd_ptr_hexa(fd, arg);
		*ptr += ft_len_ptr_hexa(arg) + 2;
	}
	else
	{
		ft_putstr_fd(PTR_NULL, fd);
		*ptr += ft_strlen(PTR_NULL);
	}
}

void	format_fd_di(int fd, va_list ap, int *ptr)
{
	int	arg;

	arg = va_arg(ap, int);
	ft_putnbr_fd(arg, fd);
	*ptr += ft_len_nbr(arg);
}

void	format_fd_u(int fd, va_list ap, int *ptr)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	ft_print_fd_nbr_u(fd, arg);
	*ptr += ft_len_nbr_u(arg);
}
