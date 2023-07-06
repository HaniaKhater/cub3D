/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 04:58:55 by hania             #+#    #+#             */
/*   Updated: 2023/07/04 08:44:03 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *line)
{
	while (*line && is_space(*line))
		line++;
	return (line);
}

char	*crop_id_value(char *line)
{
	char	*value;
	int		len;

	len = 0;
	line = skip_spaces(skip_spaces(line) + 2);
	while (line[len] && !is_space(line[len]) && line[len] != '\n')
		len++;
	value = ft_substr(line, 0, len);
	return (value);
}

int	char_count(char *line, char c)
{
	int	occurences;

	occurences = 0;
	while (*line)
	{
		if (*line == c)
			occurences++;
		line++;
	}
	return (occurences);
}
