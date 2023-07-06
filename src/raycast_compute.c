/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_compute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:05:10 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/06 22:10:11 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycast_dda(t_raycast *raycast, t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->mapx += raycast->stepx;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->mapy += raycast->stepy;
			raycast->side = 1;
		}
		if (game->scene.map[raycast->mapx][raycast->mapy] > '0')
			hit = 1;
	}
}

static void	raycast_get_texture(t_game *game, t_raycast *raycast)
{
	if (raycast->side == 0)
	{
		if (raycast->ray_dir_x > 0)
			raycast->texture = &(game->mlx->textures[NO]);
		else
			raycast->texture = &(game->mlx->textures[SO]);
	}
	else
	{
		if (raycast->ray_dir_y > 0)
			raycast->texture = &(game->mlx->textures[EA]);
		else
			raycast->texture = &(game->mlx->textures[WE]);
	}
}

static void	raycast_compute2(t_raycast *raycast, int line_height)
{
	raycast->wall_x -= floor((raycast->wall_x));
	raycast->tex_x = (int)(raycast->wall_x * (double)raycast->texture->w);
	if (raycast->side == 0 && raycast->ray_dir_x > 0)
		raycast->tex_x = raycast->texture->w - raycast->tex_x - 1;
	if (raycast->side == 1 && raycast->ray_dir_y < 0)
		raycast->tex_x = raycast->texture->w - raycast->tex_x - 1;
	raycast->step = (float)raycast->texture->h / (float)line_height;
	raycast->tex_pos = (raycast->draw_start - HEIGHT / 2.0f
			+ line_height / 2.0f) * raycast->step;
}

void	raycast_compute(int x, t_game *game, t_raycast *raycast)
{
	double		perp_wall_dist;
	int			line_height;

	raycast_init(raycast, game, x);
	raycast_dda(raycast, game);
	if (raycast->side == 0)
		perp_wall_dist = (raycast->side_dist_x - raycast->delta_dist_x);
	else
		perp_wall_dist = (raycast->side_dist_y - raycast->delta_dist_y);
	line_height = (int)(HEIGHT / perp_wall_dist);
	raycast->draw_start = -line_height / 2 + HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = line_height / 2 + HEIGHT / 2;
	if (raycast->draw_end >= HEIGHT)
		raycast->draw_end = HEIGHT - 1;
	raycast_get_texture(game, raycast);
	if (raycast->side == 0)
		raycast->wall_x = game->player.pos_y + perp_wall_dist
			* raycast->ray_dir_y;
	else
		raycast->wall_x = game->player.pos_x + perp_wall_dist
			* raycast->ray_dir_x;
	raycast_compute2(raycast, line_height);
}
