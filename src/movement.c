/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:59:13 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/04 15:47:41 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_move(t_game *game, double move_dir, double move_plane)
{
	if (move_dir != 0)
	{
		if (game->scene.map[(int)(game->player.pos_x + game->player.dir_x
				* move_dir)][(int)(game->player.pos_y)] == '0')
			game->player.pos_x += game->player.dir_x * move_dir;
		if (game->scene.map[(int)(game->player.pos_x)][(int)(game->player.pos_y
				+ game->player.dir_y * move_dir)] == '0')
			game->player.pos_y += game->player.dir_y * move_dir;
	}
	if (move_plane != 0)
	{
		if (game->scene.map[(int)(game->player.pos_x + game->player.plane_x
				* move_plane)][(int)(game->player.pos_y)] == '0')
			game->player.pos_x += game->player.plane_x * move_plane;
		if (game->scene.map[(int)(game->player.pos_x)][(int)(game->player.pos_y
				+ game->player.plane_y * move_plane)] == '0')
			game->player.pos_y += game->player.plane_y * move_plane;
	}
}

static void	game_rotate(t_game *game, double rotate)
{
	double	old_x;

	old_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rotate)
		- game->player.dir_y * sin(rotate);
	game->player.dir_y = old_x * sin(rotate) + game->player.dir_y * cos(rotate);
	old_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rotate)
		- game->player.plane_y * sin(rotate);
	game->player.plane_y = old_x * sin(rotate) + game->player.plane_y
		* cos(rotate);
}

void	game_update_moves(t_game *game)
{
	if (game->key_press[MOVE_UP] == 1)
		game_move(game, MOVE, 0);
	if (game->key_press[MOVE_DOWN] == 1)
		game_move(game, -MOVE, 0);
	if (game->key_press[MOVE_RIGHT] == 1)
		game_move(game, 0, MOVE);
	if (game->key_press[MOVE_LEFT] == 1)
		game_move(game, 0, -MOVE);
	if (game->key_press[ARROW_RIGHT] == 1)
		game_rotate(game, ROTATE);
	if (game->key_press[ARROW_LEFT] == 1)
		game_rotate(game, -ROTATE);
}
