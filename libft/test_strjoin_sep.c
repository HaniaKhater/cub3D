/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchan--r <rchan--r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:08:23 by rchan--r          #+#    #+#             */
/*   Updated: 2023/02/16 11:40:08 by rchan--r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	char	*sep;
	char	*join;

	printf("isspace: %d\n", ft_isspace(' '));
	if (argc != 3)
		return (0);
	s1 = ft_strdup(argv[0]);
	s2 = ft_strdup(argv[1]);
	sep = ft_strdup(argv[2]);
	join = ft_strjoin_sep(s1, s2, sep);
	printf("join_sep: %s\n", join);
	free(join);
	free(s1);
	free(s2);
	free(sep);
}
