/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:22:58 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/04 16:21:31 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	raycast_fill_img(t_game *game, int x, int y, t_raycast *raycast)
{
	raycast->tex_y = ((int)raycast->tex_pos) % (raycast->texture->h);
	raycast->tex_pos += raycast->step;
	if (raycast->texture->buf == NULL)
		return (0);
	ft_memcpy(game->mlx->frame.buf
		+ ((game->mlx->frame.size_line * y) + x * game->mlx->frame.bpp),
		raycast->texture->buf + ((raycast->texture->size_line * raycast->tex_y)
			+ raycast->tex_x * raycast->texture->bpp), game->mlx->frame.bpp);
	return (1);
}

int	raycast(t_game *game)
{
	int			x;
	int			y;
	t_raycast	raycast;

	game_update_moves(game);
	x = 0;
	while (x < WIDTH)
	{
		raycast_compute(x, game, &raycast);
		y = 0;
		while (y < HEIGHT)
		{
			if (raycast.draw_start <= y && y <= raycast.draw_end)
			{
				if (raycast_fill_img(game, x, y, &raycast) == 0)
					return (0);
			}
			else if (fill_frame_ceiling_floor(game, x, y) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
