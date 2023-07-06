/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:53:16 by rchan--r          #+#    #+#             */
/*   Updated: 2022/05/15 21:54:07 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	format_c(va_list ap, int *ptr)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	*ptr += 1;
}

void	format_s(va_list ap, int *ptr)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s != NULL)
	{
		ft_putstr_fd(s, 1);
		*ptr += ft_strlen(s);
	}
	else
	{
		ft_putstr_fd(STR_NULL, 1);
		*ptr += ft_strlen(STR_NULL);
	}
}

void	format_p(va_list ap, int *ptr)
{
	size_t	arg;

	arg = va_arg(ap, size_t);
	if (arg != 0)
	{
		write(1, "0x", 2);
		ft_print_ptr_hexa(arg);
		*ptr += ft_len_ptr_hexa(arg) + 2;
	}
	else
	{
		ft_putstr_fd(PTR_NULL, 1);
		*ptr += ft_strlen(PTR_NULL);
	}
}

void	format_di(va_list ap, int *ptr)
{
	int	arg;

	arg = va_arg(ap, int);
	ft_putnbr_fd(arg, 1);
	*ptr += ft_len_nbr(arg);
}

void	format_u(va_list ap, int *ptr)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	ft_print_nbr_u(arg);
	*ptr += ft_len_nbr_u(arg);
}
