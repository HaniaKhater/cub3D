/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:00:09 by hania             #+#    #+#             */
/*   Updated: 2023/07/04 16:16:37 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scene	*init_scene(void)
{
	t_scene	*new;

	new = (t_scene *)malloc(sizeof(t_scene));
	if (!new)
		return (NULL);
	new->textures[0] = NULL;
	new->textures[1] = NULL;
	new->textures[2] = NULL;
	new->textures[3] = NULL;
	new->floor_color = 17000000;
	new->ceiling_color = 17000000;
	new->map = NULL;
	return (new);
}

void	free_scene(t_scene *input)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (input->textures[i] != NULL)
		{
			free(input->textures[i]);
			input->textures[i] = NULL;
		}
		i++;
	}
	i = find_height(input->map);
	if (input && input->map && input->map[i])
	{
		while (input->map[i])
		{
			free(input->map[i]);
			i--;
		}
		free(input->map);
	}
	if (input)
		free(input);
}

void	print_scene(t_scene *input)
{
	int	i;

	i = 0;
	if (!input)
		return ;
	if (input->textures[i])
	{
		while (input->textures[i] && i < 4)
		{
			printf("Texture %d: %s\n", i + 1, input->textures[i]);
			i++;
		}
		printf("Floor color: %d\n", input->floor_color);
		printf("Ceiling color: %d\n", input->ceiling_color);
	}
	i = 0;
	if (input->map && input->map[i])
	{
		ft_printf("Map:\n");
		while (input->map[i])
			ft_printf("%s", input->map[i++]);
	}
}

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	if (arr)
		free(arr);
	return ;
}

void	t_scene_free(t_scene scene)
{
	int	i;

	i = 3;
	if (scene.textures)
	{
		while (scene.textures[i] && i >= 0)
			free(scene.textures[i--]);
	}
	if (scene.map != NULL)
	{
		i = 0;
		while (scene.map[i] != NULL)
		{
			free(scene.map[i]);
			i++;
		}
		free(scene.map);
	}
}
