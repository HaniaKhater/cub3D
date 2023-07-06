/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:48:44 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/04 15:44:40 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_up_hook(int keycode, void *param)
{
	if (keycode == XK_Escape)
		return (mlx_loop_end(((t_game *)param)->mlx->mlx_ptr));
	if (keycode == XK_Left)
		(((t_game *)param)->key_press)[ARROW_LEFT] = 0;
	if (keycode == XK_Right)
		(((t_game *)param)->key_press)[ARROW_RIGHT] = 0;
	if (keycode == XK_s)
		(((t_game *)param)->key_press)[MOVE_DOWN] = 0;
	if (keycode == XK_w)
		(((t_game *)param)->key_press)[MOVE_UP] = 0;
	if (keycode == XK_a)
		(((t_game *)param)->key_press)[MOVE_LEFT] = 0;
	if (keycode == XK_d)
		(((t_game *)param)->key_press)[MOVE_RIGHT] = 0;
	return (0);
}

int	key_down_hook(int keycode, void *param)
{
	if (keycode == XK_Left)
		(((t_game *)param)->key_press)[ARROW_LEFT] = 1;
	if (keycode == XK_Right)
		(((t_game *)param)->key_press)[ARROW_RIGHT] = 1;
	if (keycode == XK_s)
		(((t_game *)param)->key_press)[MOVE_DOWN] = 1;
	if (keycode == XK_w)
		(((t_game *)param)->key_press)[MOVE_UP] = 1;
	if (keycode == XK_a)
		(((t_game *)param)->key_press)[MOVE_LEFT] = 1;
	if (keycode == XK_d)
		(((t_game *)param)->key_press)[MOVE_RIGHT] = 1;
	return (1);
}

int	close_window(void *param)
{
	return (mlx_loop_end(((t_mlx *)param)->mlx_ptr));
}
