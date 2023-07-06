/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:14:21 by hania             #+#    #+#             */
/*   Updated: 2023/07/04 11:51:54 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_line(int *i, char *line, int fd)
{
	(*i)++;
	free(line);
	return (get_next_line(fd));
}

static char	**read_map(char *path)
{
	char			**map;
	char			*line;
	static int		i[3] = {0, 0, 0};
	int				fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line && (i[0] - i[1]) < 6)
	{
		if (is_empty(line))
			i[1]++;
		line = read_line(&i[0], line, fd);
	}
	while (line && is_empty(line))
		line = read_line(&i[1], line, fd);
	map = ft_calloc(count_lines(path) - (i[0] + i[1] - 2), sizeof(char *));
	while (line && map)
	{
		map[i[2]] = ft_strdup(line);
		line = read_line(&i[2], line, fd);
	}
	return (free(line), close(fd), map);
}

static bool	only_map_char(char *s)
{
	if (!s)
		return (false);
	while (*s)
	{
		if (*s != ' ' && *s != '\n' && *s != '1' && *s != '0' && *s != 'N'
			&& *s != 'E' && *s != 'S' && *s != 'W')
			return (false);
		s++;
	}
	return (true);
}

static int	player_nb(char *s)
{
	int	nb;

	nb = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == 'N' || *s == 'E' || *s == 'S' || *s == 'W')
			nb++;
		s++;
	}
	return (nb);
}

bool	valid_map(const char *path, t_scene *input)
{
	int		player;
	int		i;

	i = 0;
	player = 0;
	input->map = read_map((char *)path);
	if (input->map == NULL)
		return (false);
	while (input->map[i])
	{
		if (!only_map_char(input->map[i]))
			return (false);
		player += player_nb(input->map[i]);
		i++;
	}
	if (player != 1)
		return (false);
	return (true);
}
