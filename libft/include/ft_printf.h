/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:18:23 by rchan--r          #+#    #+#             */
/*   Updated: 2023/03/30 15:27:44 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# if defined __APPLE__
#  define PTR_NULL "0x0"
# else 
#  define PTR_NULL "(nil)"
# endif

# define STR_NULL "(null)"

/* UTILS */
int		ft_len_ptr_hexa(size_t l);
int		ft_len_nbr(int n);
int		ft_len_nbr_u(unsigned int u);

/* FT_PRINTF */
int		ft_printf(const char *str, ...);
void	ft_print_ptr(size_t l);
void	ft_print_ptr_hexa(size_t l);
void	ft_print_ptr_upper_hexa(size_t l);
void	ft_print_nbr_u(unsigned int u);
void	format_c(va_list ap, int *ptr);
void	format_s(va_list ap, int *ptr);
void	format_p(va_list ap, int *ptr);
void	format_di(va_list ap, int *ptr);
void	format_u(va_list ap, int *ptr);
void	format_x(va_list ap, int *ptr);
void	format_upper_x(va_list ap, int *ptr);

/* FT_PRINTF_FD */
int		ft_printf_fd(int fd, const char *str, ...);
void	ft_print_fd_ptr(int fd, size_t l);
void	ft_print_fd_ptr_hexa(int fd, size_t l);
void	ft_print_fd_nbr_u(int fd, unsigned int u);
void	ft_print_fd_ptr_upper_hexa(int fd, size_t l);
void	format_fd_c(int fd, va_list ap, int *ptr);
void	format_fd_s(int fd, va_list ap, int *ptr);
void	format_fd_p(int fd, va_list ap, int *ptr);
void	format_fd_di(int fd, va_list ap, int *ptr);
void	format_fd_u(int fd, va_list ap, int *ptr);
void	format_fd_x(int fd, va_list ap, int *ptr);
void	format_fd_upper_x(int fd, va_list ap, int *ptr);
#endif
