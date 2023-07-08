/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 02:36:21 by hkhater           #+#    #+#             */
/*   Updated: 2021/12/10 23:59:41 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
 * s = "allo"
 * len = 42
 * Pour corriger :
 * - malloc la valeur minimum entre len et ft_strlen(s + start)
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	size;

	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s + start) < len)
		size = ft_strlen(s + start);
	else
		size = len;
	p = malloc(sizeof(char) * (size + 1));
	if (!p)
		return (0);
	ft_memcpy(p, s + start, size);
	p[len] = '\0';
	return (p);
}
