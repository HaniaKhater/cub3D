/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 07:23:17 by hkhater           #+#    #+#             */
/*   Updated: 2023/07/04 00:42:31 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*check_rgb_values(char *line)
{
	int	digits;

	digits = 0;
	while (*line && ft_isdigit(*line))
	{
		digits++;
		line++;
	}
	line = skip_spaces(line);
	if ((*line != '\n' && *line != ',') || (digits > 3 || digits == 0))
		return (NULL);
	if (*line == ',')
		line = skip_spaces(line + 1);
	return (line);
}

bool	valid_color_format(char *line)
{
	int	i;

	i = 0;
	if (char_count(line, ',') != 2)
		return (false);
	line = skip_spaces(skip_spaces(line) + 1);
	while (line != NULL && i++ < 3)
	{
		line = check_rgb_values(line);
		if (!line)
			return (false);
	}
	if (*line == '\n')
		return (true);
	return (false);
}

static unsigned int	get_rgb_values(char *line)
{
	int	value;

	value = 0;
	while (*line && ft_isdigit(*line))
	{
		value *= 10;
		value += (*line - 48);
		line++;
	}
	if (value < 0 || value > 255)
		return (17000000);
	return (value);
}

static unsigned int	rgb_to_dec(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r * 65536) + (g * 256) + b);
}

unsigned int	get_color_value(char *line)
{
	int				i;
	unsigned int	rgb[3];

	i = 0;
	rgb[0] = 17000000;
	rgb[1] = 17000000;
	rgb[2] = 17000000;
	if (!valid_color_format(line))
		return (17000000);
	line = skip_spaces(skip_spaces(line) + 1);
	while (*line && i < 3)
	{
		rgb[i] = get_rgb_values(line);
		if (rgb[i] == 17000000)
			break ;
		line = check_rgb_values(line);
		i++;
	}
	if (rgb[i] == 17000000)
		return (17000000);
	return (rgb_to_dec(rgb[0], rgb[1], rgb[2]));
}
