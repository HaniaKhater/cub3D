/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:01:03 by rchan--r          #+#    #+#             */
/*   Updated: 2022/02/05 19:35:45 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	char	*res;

	len1 = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	j = len1 - 1;
	while (j != 0 && ft_strchr(set, s1[j]) != NULL)
		j--;
	if (j < i)
	{
		res = malloc(sizeof(char));
		if (res != NULL)
			res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (j - i + 2));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1 + i, j - i + 2);
	return (res);
}
