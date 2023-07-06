/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:19:41 by hkhater           #+#    #+#             */
/*   Updated: 2023/07/04 16:20:18 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_get_dimensions(t_game *g, int *w, int *height, int *nb_pixels)
{
	int		j;
	int		dim_screen;

	*w = 0;
	while (g->scene.map[*w] != NULL)
	{
		j = 0;
		while (g->scene.map[*w][j] != '\n' && g->scene.map[*w][j] != '\0')
			j++;
		if (j > *height)
			*height = j;
		*w += 1;
	}
	if (*w >= *height)
	{
		dim_screen = 0.1 * WIDTH;
		*nb_pixels = dim_screen / *w;
	}
	else
	{
		dim_screen = 0.1 * HEIGHT;
		*nb_pixels = dim_screen / *height;
	}
	*height *= *nb_pixels;
	*w *= *nb_pixels;
}

void	minimap_fill_pixel(t_game *game, int nb_p, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_p)
	{
		j = 0;
		while (j < nb_p)
		{
			if (game->scene.map[x][y] == '0')
				img_fill_pixel(game->mlx->frame, nb_p * x + i,
					nb_p * y + j, WHITE);
			else
				img_fill_pixel(game->mlx->frame, nb_p * x + i,
					nb_p * y + j, BLACK);
			j++;
		}
		i++;
	}
}
