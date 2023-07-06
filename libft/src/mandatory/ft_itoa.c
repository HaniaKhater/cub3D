/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:41:29 by rchan--r          #+#    #+#             */
/*   Updated: 2022/02/12 20:50:51 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenint(int n)
{
	int	res;

	res = 1;
	while (n / 10 != 0)
	{
		res += 1;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		l;
	int		minus;

	l = ft_lenint(n);
	minus = 0;
	if (n < 0)
		minus = 1;
	res = malloc(sizeof(char) * (l + minus + 1));
	if (res == NULL)
		return (NULL);
	if (minus)
	{
		res[0] = '-';
		res++;
	}
	res[l--] = '\0';
	while (l >= 0)
	{
		res[l--] = (1 - minus) * (n % 10) + minus * (-(n % 10)) + 48;
		n /= 10;
	}
	if (minus)
		return (res - 1);
	return (res);
}
