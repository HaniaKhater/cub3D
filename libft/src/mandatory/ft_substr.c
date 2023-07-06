/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:10:57 by rchan--r          #+#    #+#             */
/*   Updated: 2022/02/05 17:42:43 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*res;	

	len_s = ft_strlen(s);
	if (start > len_s || len == 0)
	{
		res = malloc(sizeof(char));
		if (res == NULL)
			return (NULL);
		*res = '\0';
		return (res);
	}
	len_s = ft_strlen(s + start);
	if (len <= len_s)
		len_s = len;
	res = (char *)malloc(sizeof(char) * (len_s + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy((char *)res, s + start, len_s + 1);
	return (res);
}
