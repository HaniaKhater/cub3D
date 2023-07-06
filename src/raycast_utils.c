/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:56:51 by hkhater           #+#    #+#             */
/*   Updated: 2023/07/06 22:10:11 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_init_step(t_raycast *rc, t_game *g)
{
	if (rc->ray_dir_x < 0)
	{
		rc->stepx = -1;
		rc->side_dist_x = (g->player.pos_x - rc->mapx) * rc->delta_dist_x;
	}
	else
	{
		rc->stepx = 1;
		rc->side_dist_x = (rc->mapx + 1.0 - g->player.pos_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->stepy = -1;
		rc->side_dist_y = (g->player.pos_y - rc->mapy) * rc->delta_dist_y;
	}
	else
	{
		rc->stepy = 1;
		rc->side_dist_y = (rc->mapy + 1.0 - g->player.pos_y) * rc->delta_dist_y;
	}
}

void	raycast_init(t_raycast *rc, t_game *game, int x)
{
	rc->camerax = 2 * x / (double)WIDTH - 1;
	rc->ray_dir_x = game->player.dir_x + game->player.plane_x * rc->camerax;
	rc->ray_dir_y = game->player.dir_y + game->player.plane_y * rc->camerax;
	rc->mapx = (int)game->player.pos_x;
	rc->mapy = (int)game->player.pos_y;
	if (rc->ray_dir_x == 0)
		rc->delta_dist_x = 1e30;
	else if (rc->ray_dir_x > 0)
		rc->delta_dist_x = 1 / rc->ray_dir_x;
	else
		rc->delta_dist_x = -1 / rc->ray_dir_x;
	if (rc->ray_dir_y == 0)
		rc->delta_dist_y = 1e30;
	else if (rc->ray_dir_y > 0)
		rc->delta_dist_y = 1 / rc->ray_dir_y;
	else
		rc->delta_dist_y = -1 / rc->ray_dir_y;
	raycast_init_step(rc, game);
}
