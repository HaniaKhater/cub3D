cc				= gcc
CFLAGS			= -Wall -Werror -Wextra -MMD -g3
LIB				= -lX11 -lXext -lm

NAME			= cub3D

DIR_MLX			= ./minilibx-linux/
DIR_INC_MLX		= $(DIR_MLX)

DIR_LIBFT		= libft/
DIR_INC_LIBFT	= $(DIR_LIBFT)include/

DIR_OBJ			= bin/
DIR_INC_SL		= include/
DIR_SRC			= src/

LIBFT			= $(DIR_LIBFT)libft.a
MLX				= $(DIR_MLX)libmlx.a

SRC				= main.c \
				  game.c \
				  player_init.c \
				  display_frame.c \
				  minimap.c \
				  t_img.c \
				  t_mlx.c \
				  hooks.c \
				  img_fill_pixel.c \
				  raycast.c \
				  raycast_compute.c \
				  raycast_utils.c \
				  movement.c \
				  parsing.c \
				  identifiers.c \
				  identifier_utils.c \
				  count_lines.c \
				  map.c \
				  map_utils.c \
				  rgb.c \
				  t_scene.c \
				  walls.c \

OBJ				= $(addprefix $(DIR_OBJ), $(SRC:.c=.o))
DPD				= $(OBJ:.o=.d)

all:			$(NAME)

$(LIBFT):
				make -C $(DIR_LIBFT)

$(MLX):
				make -C $(DIR_MLX)

$(DIR_OBJ):
				mkdir $@

$(DIR_OBJ)%.o:	$(DIR_SRC)%.c
				$(cc) $(CFLAGS) -I$(DIR_INC_SL) -I$(DIR_INC_LIBFT) -I$(DIR_INC_MLX) -c $< -o $@

-include $(DPD)

$(NAME):		$(LIBFT) $(MLX) $(DIR_OBJ) $(OBJ)
				$(cc) $(CFLAGS) $(OBJ) -o $(NAME) -I$(DIR_INC_SL) -I$(DIR_INC_LIBFT) -I$(DIR_INC_MLX) -L$(DIR_LIBFT) -lft -L$(DIR_MLX) -lmlx $(LIB)

clean:
				make -C $(DIR_LIBFT) clean
				make -C $(DIR_MLX) clean
				rm -rf $(DIR_OBJ)

fclean:			clean
				make -C $(DIR_LIBFT) fclean
				rm -f $(NAME)

re:				fclean	all

.PHONY:			all fclean clean re
