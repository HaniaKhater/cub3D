/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 05:00:59 by hania             #+#    #+#             */
/*   Updated: 2023/07/04 07:01:50 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line(int fd)
{
	char	buff;
	char	line[2000];
	int		b;
	int		i;

	if (fd < 0)
		return (NULL);
	i = 0;
	b = read(fd, &buff, 1);
	while (b > 0)
	{
		line[i++] = buff;
		if (buff == '\n')
			break ;
		b = read(fd, &buff, 1);
	}
	line[i] = '\0';
	if (b <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	count_lines(char *path)
{
	int		line_count;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (line_count);
}

bool	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

bool	is_empty(const char *line)
{
	if (!line)
		return (true);
	while (*line)
	{
		if (!is_space(*line) && *line != '\n')
			return (false);
		line++;
	}
	return (true);
}
