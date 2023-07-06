/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:14:36 by hania             #+#    #+#             */
/*   Updated: 2023/07/04 12:46:22 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_type(char *line)
{
	int			type;
	static char	*id[6] = {"NO", "SO", "WE", "EA", "F", "C"};

	type = 0;
	if (!line)
		return (-1);
	while (*line == ' ' || *line == '\t')
		line++;
	while (type < 6)
	{
		if (ft_strnstr(line, id[type], ft_strlen(id[type])) == line)
			return (type);
		type++;
	}
	return (-1);
}

static char	**read_identifiers(char *path)
{
	char	**ids;
	char	*line;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ids = ft_calloc(7, sizeof(*ids));
	if (ids == NULL)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < 6)
	{
		if (!is_empty(line) && find_type(line) == -1)
			break ;
		if (!is_empty(line))
			ids[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (ids);
}

static bool	id_count_valid(char *identifier)
{
	static int	count[6];
	int			type;

	if ((identifier == NULL) && ((count[NO] != 1 || count[SO] != 1
				|| count[EA] != 1 || count[WE] != 1)
			|| (count[F] != 1 || count[C] != 1)))
		return (false);
	if (identifier != NULL)
	{
		type = find_type(identifier);
		if (type != -1)
			count[type] += 1;
	}
	if ((count[NO] > 1 || count[SO] > 1 || count[EA] > 1
			|| count[WE] > 1) || (count[F] > 1 || count[C] > 1))
		return (false);
	return (true);
}

bool	save_identifiers(char **ids, t_scene *input)
{
	int	i;
	int	type;

	i = 0;
	while (ids[i] && i < 6)
	{
		type = find_type(ids[i]);
		if (type < 4)
		{
			input->textures[type] = crop_id_value(ids[i]);
			if (!is_readable(input->textures[type]))
				return (false);
		}
		else if (type == 4)
			input->floor_color = get_color_value(ids[i]);
		else if (type == 5)
			input->ceiling_color = get_color_value(ids[i]);
		i++;
	}
	if (input->ceiling_color == 17000000 || input->floor_color == 17000000)
		return (false);
	return (true);
}

bool	valid_identifiers(const char *path, t_scene *input)
{
	char	**ids;
	int		i;

	i = 0;
	ids = read_identifiers((char *)path);
	if (ids == NULL)
		return (false);
	while (ids[i] && i < 6)
	{
		if (!id_count_valid(ids[i]))
			return (free_str_arr(ids), false);
		i++;
	}
	if (!id_count_valid(NULL) || !save_identifiers(ids, input))
		return (free_str_arr(ids), false);
	return (free_str_arr(ids), true);
}
