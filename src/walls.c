/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:27:26 by hkhater           #+#    #+#             */
/*   Updated: 2023/07/04 12:11:55 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	bad(char c)
{
	return (c != ' ' && c != '1');
}

static bool	check_neighbors(char **map, size_t x, size_t y)
{
	if (bad(map[x - 1][y - 1]) || bad(map[x - 1][y]) || bad(map[x - 1][y + 1])
		|| bad(map[x][y - 1]) || bad(map[x][y + 1]) || bad(map[x + 1][y - 1])
		|| bad(map[x + 1][y]) || bad(map[x + 1][y + 1]))
		return (false);
	return (true);
}

bool	surrounded_walls(char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 2])
		{
			if (map[i][j] == ' ')
				if (!check_neighbors(map, i, j))
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}
