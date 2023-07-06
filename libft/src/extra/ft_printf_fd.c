/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:17:07 by rchan--r          #+#    #+#             */
/*   Updated: 2023/03/30 15:25:38 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_fd(int fd, va_list ap, char c, int *ptr)
{
	if (c == 'c')
		format_fd_c(fd, ap, ptr);
	else if (c == 's')
		format_fd_s(fd, ap, ptr);
	else if (c == 'p')
		format_fd_p(fd, ap, ptr);
	else if (c == 'd')
		format_fd_di(fd, ap, ptr);
	else if (c == 'i')
		format_fd_di(fd, ap, ptr);
	else if (c == 'u')
		format_fd_u(fd, ap, ptr);
	else if (c == 'x')
		format_fd_x(fd, ap, ptr);
	else if (c == 'X')
		format_fd_upper_x(fd, ap, ptr);
	else
	{
		write(fd, "%", 1);
		(*ptr)++;
	}
}

int	ft_printf_fd(int fd, const char *str, ...)
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
			format_fd(fd, ap, str[i + 1], &res);
			i++;
		}
		else
		{
			write(fd, str + i, 1);
			res += 1;
		}
		i++;
	}
	va_end(ap);
	return (res);
}
