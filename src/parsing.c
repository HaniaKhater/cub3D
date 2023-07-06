/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:26:27 by hania             #+#    #+#             */
/*   Updated: 2023/07/04 12:33:10 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_readable(const char *path)
{
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	tmp = get_next_line(fd);
	if (!tmp)
		return (close(fd), free(tmp), false);
	close(fd);
	return (free(tmp), true);
}

bool	parse(char *path, t_scene *input)
{
	if (!is_readable(path))
		return (false);
	if (!valid_identifiers(path, input))
		return (false);
	if (!valid_map(path, input))
		return (false);
	adapt_map(input);
	adapt_map(input);
	if (!surrounded_walls(input->map))
		return (false);
	return (true);
}
