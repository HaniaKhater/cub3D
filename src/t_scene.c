/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:00:09 by hania             #+#    #+#             */
/*   Updated: 2023/07/08 23:34:11 by hkhater          ###   ########.fr       */
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

	i = 3;
	while (i >= 0)
	{
		if (input->textures[i] != NULL)
		{
			free(input->textures[i]);
			input->textures[i] = NULL;
		}
		i--;
	}
	if (input->map)
		free_str_arr(input->map);
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
