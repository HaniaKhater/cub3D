/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:52:25 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/14 11:02:55 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(char const *s1, char const *sep, char const *s2)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, sep);
	if (tmp == NULL)
		return (NULL);
	res = ft_strjoin(tmp, s2);
	free(tmp);
	return (res);
}
