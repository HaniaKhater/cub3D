/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:56:42 by rchan--r          #+#    #+#             */
/*   Updated: 2023/01/16 16:44:00 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	if (*little == '\0')
		return ((char *)big);
	len_little = ft_strlen(little);
	i = 0;
	while (big[i] && i + len_little <= len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
