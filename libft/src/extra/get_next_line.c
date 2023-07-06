/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:43:55 by rchan--r          #+#    #+#             */
/*   Updated: 2023/01/17 14:47:03 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*res_gnl(int r, char *buf, char *res, char **ptr)
{	
	free(buf);
	*ptr = NULL;
	if (r <= 0 && res != NULL && ft_strlen_end(res, '\0') != 0)
		return (res);
	else if (r <= 0 && res != NULL)
		free(res);
	return (NULL);
}

static char	*init_buf(int size, int *r)
{
	char	*buf;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (size));
	if (buf == NULL)
		return (NULL);
	buf[0] = '\0';
	*r = BUFFER_SIZE;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*ptr = NULL;
	char		*buf;
	char		*res;
	int			r;

	if (ptr == NULL)
	{
		buf = init_buf(BUFFER_SIZE + 1, &r);
		if (buf == NULL)
			return (NULL);
		ptr = buf;
	}
	else
		buf = ptr;
	res = init_buf(1, &r);
	if (res == NULL)
		return (free(buf), NULL);
	if (process_buf(buf, &res, &r, fd) == 1)
		return (res);
	while (r > 0 && res != NULL)
	{
		if (process_buf(buf, &res, &r, fd) == 1)
			return (res);
	}
	return (res_gnl(r, buf, res, &ptr));
}
