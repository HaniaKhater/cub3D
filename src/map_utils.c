/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:25:49 by hania             #+#    #+#             */
/*   Updated: 2023/07/06 22:34:10 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	find_width(char **raw)
{
	int		i;
	size_t	max;

	i = 0;
	max = 0;
	while (raw && raw[i])
	{
		if (ft_strlen(raw[i]) > max)
			max = ft_strlen(raw[i]);
		i++;
	}
	return (max);
}

size_t	find_height(char **raw)
{
	size_t	i;

	i = 0;
	while (raw && raw[i])
		i++;
	if (i > 0 && !is_empty(raw[i - 1]))
		return (i);
	while (i > 0 && raw[i - 1])
	{
		if (is_empty(raw[i - 1]))
			i--;
		else
			break ;
	}
	return (i);
}

static void	adapt_str(char *src, char *dest, size_t len)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return ;
	if (!src[i] || src[i] == '\n')
	{		
		ft_memset(dest, ' ', len - 1);
		dest[len - 1] = '\n';
		dest[len] = '\0';
		return ;
	}
	while (src[i] && src[i] != '\n')
		i++;
	dest[0] = ' ';
	ft_memcpy((dest + 1), src, i);
	ft_memset(dest + i + 1, ' ', len - i);
	dest[len - 1] = '\n';
	dest[len] = '\0';
}

static void	fill_frame(char **raw, char **framed, size_t width, size_t height)
{
	size_t	i;

	i = 0;
	adapt_str("\n", framed[0], width);
	while (i < height - 2)
	{
		adapt_str(raw[i], framed[i + 1], width);
		i++;
	}
	adapt_str("\n", framed[height - 2], width);
	adapt_str("\n", framed[height - 1], width);
	framed[height] = NULL;
	i = 0;
	while (raw[i])
	{
		free(raw[i]);
		raw[i] = NULL;
		i++;
	}
	free(raw);
}

void	adapt_map(t_scene *input)
{
	char	**framed;
	size_t	width;
	size_t	height;
	size_t	i;

	i = 0;
	width = find_width(input->map) + 2;
	height = find_height(input->map) + 3;
	framed = (char **)malloc(sizeof(char *) * (height + 1));
	if (!framed)
		return ;
	while (i < height)
		framed[i++] = malloc(sizeof(char) * (width + 1));
	fill_frame(input->map, framed, width, height);
	input->map = framed;
}
