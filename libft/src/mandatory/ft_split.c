/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:52:07 by rchan--r          #+#    #+#             */
/*   Updated: 2022/02/05 17:46:34 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbelements(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	res = 0;
	while (s[i])
	{
		res += 1;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (res);
}

const char	*ft_nextword(char const *s, char c)
{
	int	i;

	i = 0;
	if (s[i] == c)
	{
		while (s[i] && s[i] == c)
			i++;
		return (s + i);
	}
	while (s[i] && s[i] != c)
		i++;
	return (s + i);
}

int	ft_freetab(char **tab, int n)
{
	int	i;

	if (tab[n] != NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	const char	*sp1;
	int			nb_words;
	int			i;

	nb_words = ft_nbelements(s, c);
	res = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (*s == c)
		s = ft_nextword(s, c);
	while (i < nb_words)
	{
		sp1 = ft_nextword(s, c);
		res[i] = ft_substr(s, 0, sp1 - s);
		if (ft_freetab(res, i))
			return (NULL);
		s = sp1;
		if (*s == c)
			s = ft_nextword(s, c);
		i++;
	}
	res[nb_words] = NULL;
	return (res);
}
