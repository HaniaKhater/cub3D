/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:15:07 by hkhater           #+#    #+#             */
/*   Updated: 2023/07/08 21:36:50 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	t_mlx_is_valid(t_mlx *mlx)
{
	if (mlx == NULL || mlx->mlx_ptr != NULL || mlx->win_ptr != NULL)
		return (1);
	return (0);
}

static void	t_img_free(t_img *img)
{
	if (img == NULL)
		return ;
	if (img->img_ptr != NULL)
	{
		mlx_destroy_image(img->mlx_ptr, img->img_ptr);
		img->img_ptr = NULL;
	}
}

static int	t_mlx_textures_init(t_mlx *mlx, char *files[4])
{
	int			i;

	if (t_mlx_is_valid(mlx) == 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		mlx->textures[i].img_ptr = NULL;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (t_img_init_file(mlx->mlx_ptr, mlx->textures + i,
				files[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_mlx	*t_mlx_init(char *files[4])
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->frame.img_ptr = NULL;
	if (mlx == NULL)
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (NULL);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (mlx->win_ptr == NULL)
		return (mlx_destroy_display(mlx->mlx_ptr), free(mlx->mlx_ptr), NULL);
	if (t_mlx_textures_init(mlx, files) == 0)
		return (t_mlx_free(mlx), NULL);
	if (t_img_init(mlx->mlx_ptr, &(mlx->frame), WIDTH, HEIGHT) == 0)
		return (t_mlx_free(mlx), NULL);
	return (mlx);
}

void	t_mlx_free(t_mlx *mlx)
{
	int	i;

	if (mlx->mlx_ptr == NULL)
		return ;
	t_img_free(&(mlx->frame));
	i = 0;
	while (i < 4)
	{
		if (mlx->textures[i].img_ptr != NULL)
			t_img_free(&(mlx->textures[i]));
		i++;
	}
	if (mlx->win_ptr != NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->win_ptr = NULL;
	}
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	mlx->mlx_ptr = NULL;
	free(mlx);
}
