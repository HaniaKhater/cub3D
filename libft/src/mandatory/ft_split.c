/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhater <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 03:35:25 by hkhater           #+#    #+#             */
/*   Updated: 2021/12/12 03:14:03 by hkhater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char const c)
{
	size_t	count;
	size_t	i;

	if (s[0])
	{
		i = 1;
		count = 0;
		if (s[0] != c)
			count = 1;
		while (s[i])
		{
			if (s[i - 1] == c && s[i] != c)
				count++;
			i++;
		}
		return (count);
	}
	else
		return (0);
}

static size_t	ft_wordlen(char const *s, const char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_create_word(char const *s, size_t *i, char c)
{
	char	*word;
	size_t	k;

	k = 0;
	word = (char *)malloc(sizeof(char) * (ft_wordlen(s + *i, c) + 1));
	if (!word)
		return (NULL);
	while (s[*i] && s[*i] != c)
		word[k++] = s[(*i)++];
	word[k] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	sp = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!sp)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			sp[j] = ft_create_word(s, &i, c);
			if (!sp[j])
				return (NULL);
			j++;
		}
	}
	sp[j] = 0;
	return (sp);
}
