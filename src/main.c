/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:08:52 by hania             #+#    #+#             */
/*   Updated: 2023/07/07 00:35:21 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_scene	*input;
	t_game	game;

	if (ac != 2 || ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
		return (ft_printf("Error\nMissing map. Try ./cub3d maps/map.cub\n"), 1);
	input = init_scene();
	if (!parse(av[1], input))
		return (free_scene(input), ft_printf("Error\nIncorrect input\n"), 1);
	print_scene(input);
	if (game_init(&game, input) == 0)
		return (1);
	if (t_mlx_is_valid(game.mlx) == 0)
		return (1);
	mlx_hook(game.mlx->win_ptr, 2, 1L << 0, &key_down_hook, &game);
	mlx_hook(game.mlx->win_ptr, 3, 1L << 1, &key_up_hook, &game);
	mlx_hook(game.mlx->win_ptr, 17, 0, &close_window, game.mlx);
	mlx_loop_hook(game.mlx->mlx_ptr, &display_frame, &game);
	mlx_loop(game.mlx->mlx_ptr);
	free_scene(input);
	game_free(game);
	return (0);
}
