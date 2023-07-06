/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:10:46 by rchan--r          #+#    #+#             */
/*   Updated: 2022/05/16 20:40:54 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_x(va_list ap, int *ptr)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	ft_print_ptr_hexa(arg);
	*ptr += ft_len_ptr_hexa(arg);
}

void	format_upper_x(va_list ap, int *ptr)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	ft_print_ptr_upper_hexa(arg);
	*ptr += ft_len_ptr_hexa(arg);
}
