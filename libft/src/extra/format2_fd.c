/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:10:46 by rchan--r          #+#    #+#             */
/*   Updated: 2023/03/30 15:29:11 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_fd_x(int fd, va_list ap, int *ptr)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	ft_print_fd_ptr_hexa(fd, arg);
	*ptr += ft_len_ptr_hexa(arg);
}

void	format_fd_upper_x(int fd, va_list ap, int *ptr)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	ft_print_fd_ptr_upper_hexa(fd, arg);
	*ptr += ft_len_ptr_hexa(arg);
}
