/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:17:07 by rchan--r          #+#    #+#             */
/*   Updated: 2022/05/15 22:00:21 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	format(va_list ap, char c, int *ptr)
{
	if (c == 'c')
		format_c(ap, ptr);
	else if (c == 's')
		format_s(ap, ptr);
	else if (c == 'p')
		format_p(ap, ptr);
	else if (c == 'd')
		format_di(ap, ptr);
	else if (c == 'i')
		format_di(ap, ptr);
	else if (c == 'u')
		format_u(ap, ptr);
	else if (c == 'x')
		format_x(ap, ptr);
	else if (c == 'X')
		format_upper_x(ap, ptr);
	else
	{
		write(1, "%", 1);
		(*ptr)++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		res;
	int		i;
	va_list	ap;

	va_start(ap, str);
	res = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			format(ap, str[i + 1], &res);
			i++;
		}
		else
		{
			write(1, str + i, 1);
			res += 1;
		}
		i++;
	}
	va_end(ap);
	return (res);
}
