/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fill_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:19:22 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/04 15:49:33 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	img_fill_pixel(t_img img, int x, int y, unsigned int color)
{
	int		i;	

	if (img.img_ptr == NULL || img.mlx_ptr == NULL)
		return (0);
	color = mlx_get_color_value(img.mlx_ptr, color);
	i = 0;
	while (i < img.bpp)
	{
		if (img.endian == 0)
			img.buf[y * img.size_line + img.bpp * x + i] = (color >> (i * 8));
		else
			img.buf[y * img.size_line + img.bpp * x + i] = (color
					>> ((img.bpp - 1 - i) * 8));
		i++;
	}
	return (1);
}
