/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:16:52 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/07 00:28:47 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_init(t_game *game, t_scene *input)
{
	if (game == NULL)
		return (0);
	game->scene = *input;
	game->player = player_init(game->scene.map);
	game->mlx = t_mlx_init(game->scene.textures);
	if (game->mlx == NULL)
		return (0);
	ft_memset(game->key_press, 0, 6);
	return (1);
}

void	game_free(t_game game)
{
	if (game.mlx != NULL)
		t_mlx_free(game.mlx);
}
