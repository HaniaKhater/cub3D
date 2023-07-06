/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:16:52 by rchan--r          #+#    #+#             */
/*   Updated: 2023/07/04 16:32:52 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_scene	scene_init(void)
{
	t_scene	scene;

	scene.textures[0] = NULL;
	scene.textures[1] = NULL;
	scene.textures[2] = NULL;
	scene.textures[3] = NULL;
	scene.floor_color = BLUE;
	scene.ceiling_color = RED;
	scene.map = NULL;
	return (scene);
}

int	game_init(t_game *game, char *path)
{
	if (game == NULL)
		return (0);
	game->scene = scene_init();
	if (parse(path, &(game->scene)) == false)
		return (0);
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
	t_scene_free(game.scene);
}
