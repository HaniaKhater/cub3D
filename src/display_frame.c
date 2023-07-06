/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:46:26 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/04 16:19:53 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_frame_ceiling_floor(t_game *game, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	if (y < HEIGHT / 2)
	{
		if (img_fill_pixel(game->mlx->frame, x, y,
				game->scene.ceiling_color) == 0)
			return (0);
	}
	else
	{
		if (img_fill_pixel(game->mlx->frame, x, y,
				game->scene.floor_color) == 0)
			return (0);
	}
	return (1);
}

static void	minimap_fill(t_game *game, int nb_pixels)
{
	int		x;
	int		y;

	x = 0;
	while (game->scene.map[x] != NULL)
	{
		y = 0;
		while (game->scene.map[x][y] != '\n')
		{
			minimap_fill_pixel(game, nb_pixels, x, y);
			y++;
		}
		x++;
	}
}

static void	minimap_update_player_position(t_game *game, int nb_pixels)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = game->player.pos_x;
	y = game->player.pos_y;
	i = 0;
	while (i < nb_pixels)
	{
		j = 0;
		while (j < nb_pixels)
		{
			img_fill_pixel(game->mlx->frame, nb_pixels * x + i,
				nb_pixels * y + j, RED);
			j++;
		}
		i++;
	}
}

static int	display_minimap(t_game *game)
{
	static int	height = 0;
	static int	width = 0;
	static int	nb_pixels = 0;

	if (nb_pixels == 0)
		minimap_get_dimensions(game, &width, &height, &nb_pixels);
	if (nb_pixels == 0)
		return (0);
	minimap_fill(game, nb_pixels);
	minimap_update_player_position(game, nb_pixels);
	return (1);
}

int	display_frame(void *param)
{
	t_game	*game;

	game = param;
	if (t_mlx_is_valid(game->mlx) == 0)
		return (0);
	if (game->mlx->frame.img_ptr == NULL)
		return (0);
	if (raycast(game) == 0)
		return (0);
	if (display_minimap(game) == 0)
		return (0);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, \
			game->mlx->frame.img_ptr, 0, 0);
	return (1);
}
