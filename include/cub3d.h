/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:18:20 by hania             #+#    #+#             */
/*   Updated: 2023/07/08 23:50:01 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <math.h>
# include "libft.h"
# include "./struct.h"
# include <stdio.h>

// PARSING.C
bool			is_readable(const char *path);
bool			parse(char *path, t_scene *input);

// SCENE.C
t_scene			*init_scene(void);
void			free_scene(t_scene *input);
void			print_scene(t_scene *input);
void			free_str_arr(char **arr);
void			t_scene_free(t_scene scene);

// IDENTIFIERS.C
int				find_type(char *line);
bool			valid_identifiers(const char *path, t_scene *input);

// COUNT_LINES.C
int				count_lines(char *path);
char			*get_next_line(int fd);
bool			is_space(char c);
bool			is_empty(const char *line);

// MAP_PARSER.C
bool			valid_map(const char *path, t_scene *input);

// MAP_UTILS.C
size_t			find_width(char **raw);
size_t			find_height(char **raw);
void			adapt_map(t_scene *input);

// IDENTIFIER_UTILS.C
char			*skip_spaces(char *line);
char			*crop_id_value(char *line);
int				char_count(char *line, char c);

// RGB.C
unsigned int	get_color_value(char *line);

// WALLS.C
bool			surrounded_walls(char **map);

// GAME.C 
int				game_init(t_game *game, t_scene *input);
void			game_free(t_game game);

// IMG_FILL_DISPLAY.C
int				img_fill_pixel(t_img img, int x, int y, unsigned int color);

// MOVEMENT.C
void			game_update_moves(t_game *game);

// RAYCAST_COMPUTE.C
void			raycast_compute(int x, t_game *game, t_raycast *raycast);

// RAYCAST.C
int				raycast(t_game *game);
void			raycast_init_step(t_raycast *rc, t_game *g);
void			raycast_init(t_raycast *rc, t_game *game, int x);

// DISPLAY_FRAME.C
int				fill_frame_ceiling_floor(t_game *game, int x, int y);
int				display_frame(void *param);

// MINIMAP.C
void			minimap_get_dimensions(t_game *g, int *w, int *height,
					int *nb_pixels);
void			minimap_fill_pixel(t_game *game, int nb_p, int x, int y);

//T_IMG.C
int				t_img_init(void *mlx_ptr, t_img *img, int width, int height);
int				t_img_init_file(void *mlx_ptr, t_img *img, char *file);

// T_MLX.C
int				t_mlx_is_valid(t_mlx *mlx);
t_mlx			*t_mlx_init(char *files[4]);
void			t_mlx_free(t_mlx *mlx);

// HOOKS.C
int				key_up_hook(int keycode, void *param);
int				key_down_hook(int keycode, void *param);
int				close_window(void *param);

// PLAYER_INIT.C
t_player		player_init(char **map);

#endif
