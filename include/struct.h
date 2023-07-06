/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:33:52 by hania             #+#    #+#             */
/*   Updated: 2023/07/06 22:10:11 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define MOVE 0.1
# define ROTATE 0.08
# define PITCH	00

enum e_screensize
{
	WIDTH = 1920,
	HEIGHT = 1080
};

enum e_color
{
	RED = 16711680,
	GREEN = 65280,
	BLUE = 255,
	WHITE = 16777215,
	BLACK = 0
};

enum e_direction
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	F = 4,
	C = 5
};

enum e_key_press
{
	ARROW_LEFT,
	ARROW_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
};

typedef struct s_scene
{
	char			*textures[4];
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			**map;
}	t_scene;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_img
{
	void	*mlx_ptr;
	void	*img_ptr;
	int		w;
	int		h;
	char	*buf;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	frame;
	t_img	textures[4];
}	t_mlx;

typedef struct s_game
{
	t_mlx		*mlx;
	t_player	player;
	t_scene		scene;
	char		key_press[6];
}	t_game;

typedef struct s_raycast
{
	int				draw_start;
	int				draw_end;
	unsigned int	color;
	double			camerax;
	double			ray_dir_x;
	double			ray_dir_y;
	int				mapx;
	int				mapy;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				stepx;
	int				stepy;
	int				side;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			tex_pos;
	t_img			*texture;
	double			step;
}	t_raycast;

#endif
