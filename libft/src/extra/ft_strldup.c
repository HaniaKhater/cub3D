/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:46:39 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/15 18:37:06 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *s, size_t size)
{
	char	*res;
	size_t	len;

	if (size == 0)
		return (NULL);
	len = ft_strlen(s);
	size = ft_min(size, len + 1);
	res = malloc(sizeof(char) * (size));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s, size);
	return (res);
}
