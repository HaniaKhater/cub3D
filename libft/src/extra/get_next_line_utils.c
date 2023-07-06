/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:12:55 by rchan--r          #+#    #+#             */
/*   Updated: 2023/01/17 14:56:58 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_end(char *str, char c)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	return (len);
}

static int	is_filled(char *buf)
{
	int	i;
	int	filled;

	if (buf == NULL)
		return (0);
	i = 0;
	filled = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			filled = 1;
		i++;
	}
	return (filled);
}

static char	*fill(char *res, char *buf)
{
	int		len_res;
	int		len_buf;
	char	*tmp;
	int		i;

	len_res = ft_strlen_end(res, '\0');
	len_buf = ft_strlen_end(buf, '\n');
	tmp = malloc(sizeof(char) * (len_res + len_buf + 2));
	if (tmp != NULL)
	{
		i = -1;
		while (++i < len_res)
			tmp[i] = res[i];
		while (i < len_res + len_buf)
		{
			tmp[i] = buf[i - len_res];
			i++;
		}
		tmp[i] = '\n';
		if (is_filled(buf))
			i++;
		tmp[i] = '\0';
	}
	free(res);
	return (tmp);
}

static void	empty_buf(char *buf)
{
	int	index_nl;
	int	i;

	index_nl = 0;
	while (buf[index_nl] != '\n' && buf[index_nl] != '\0')
		index_nl++;
	if (buf[index_nl] == '\0')
		return ;
	i = 0;
	while (buf[index_nl + i + 1] != '\0' && index_nl + i < BUFFER_SIZE + 1)
	{
		buf[i] = buf[index_nl + i + 1];
		i++;
	}
	buf[i] = '\0';
}

int	process_buf(char *buf, char **ptr_res, int *r, int fd)
{
	buf[*r] = '\0';
	*ptr_res = fill(*ptr_res, buf);
	empty_buf(buf);
	if (is_filled(*ptr_res))
		return (1);
	*r = read(fd, buf, BUFFER_SIZE);
	return (0);
}
