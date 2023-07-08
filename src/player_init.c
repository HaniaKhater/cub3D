/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:18:05 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/08 21:49:20 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_fill_dir(t_player *player, double x, double y)
{
	player->dir_x = x;
	player->dir_y = y;
}

static void	player_fill_plane(t_player *player, double x, double y)
{
	player->plane_x = x;
	player->plane_y = y;
}

static void	player_fill(t_player *player, int i, int j, char c)
{
	player->pos_x = i + 0.5;
	player->pos_y = j + 0.5;
	if (c == 'N')
	{
		player_fill_dir(player, 0.01, -0.99);
		player_fill_plane(player, 0.66, 0.01);
	}
	else if (c == 'S')
	{
		player_fill_dir(player, 0.01, 0.99);
		player_fill_plane(player, -0.66, 0.01);
	}
	else if (c == 'W')
	{
		player_fill_dir(player, 0.99, 0.01);
		player_fill_plane(player, 0.01, 0.66);
	}
	else if (c == 'E')
	{
		player_fill_dir(player, -0.99, 0.01);
		player_fill_plane(player, 0.01, -0.66);
	}
}

t_player	player_init(char **map)
{
	t_player	player;
	char		c;
	int			i;
	int			j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			c = map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				player_fill(&player, i, j, c);
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (player);
}
