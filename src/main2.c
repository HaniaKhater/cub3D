/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:08:52 by hania             #+#    #+#             */
/*   Updated: 2023/07/04 15:55:40 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
		return (ft_printf("Error\nMissing map. Try ./cub3d maps/map.cub\n"), 1);
	if (game_init(&game, av[1]) == 0)
		return (0);
	if (t_mlx_is_valid(game.mlx) == 0)
		return (0);
	mlx_hook(game.mlx->win_ptr, 2, 1L << 0, &key_down_hook, &game);
	mlx_hook(game.mlx->win_ptr, 3, 1L << 1, &key_up_hook, &game);
	mlx_hook(game.mlx->win_ptr, 17, 0, &close_window, game.mlx);
	mlx_loop_hook(game.mlx->mlx_ptr, &display_frame, &game);
	mlx_loop(game.mlx->mlx_ptr);
	game_free(game);
}
