/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 03:46:39 by hkhater           #+#    #+#             */
/*   Updated: 2021/12/10 04:58:35 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count(int n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*p;
	char			sign;
	unsigned int	count;

	sign = '\0';
	if (n < 0)
		sign = '-';
	count = ft_count(n);
	p = malloc(sizeof(char) * (count + 1));
	if (!p)
		return (0);
	p[count] = '\0';
	while (count)
	{
		if (n < 0)
			p[--count] = -(n % 10) + '0';
		else
			p[--count] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		p[count] = sign;
	return (p);
}
