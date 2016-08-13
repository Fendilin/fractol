/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vterzian <vterzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:17:31 by vterzian          #+#    #+#             */
/*   Updated: 2015/02/13 13:11:13 by vterzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_word(char const *s, char c)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static char			**ft_create_tab(size_t size)
{
	char	**tab;

	tab = (char**)ft_memalloc(sizeof(char**) * size + 1);
	if (tab == NULL)
		return (NULL);
	*tab = ft_strdup("");
	return (tab);
}

static char			**ft_split(char *tmp, char c, int nbw)
{
	int		index[3];
	char	**tab;

	tab = ft_create_tab(nbw);
	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	while (tmp[index[0]] != '\0')
	{
		while (tmp[index[0]] == c)
			index[0]++;
		index[1] = index[0];
		while (tmp[index[1]] != c && tmp[index[0]] != '\0')
			index[1]++;
		if (tmp[index[1]] != '\0' || tmp[index[0]] != c)
			tab[index[2]++] = ft_strsub(tmp, index[0], index[1] - index[0]);
		index[0] = index[1];
	}
	tab[nbw] = NULL;
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*tmp;
	size_t	nbw;

	if (s == NULL || !c)
		return (NULL);
	nbw = ft_count_word(s, c);
	tmp = ft_strdup(s);
	if (tab == NULL)
		return (NULL);
	tab = ft_split(tmp, c, nbw);
	ft_strdel(&tmp);
	return (tab);
}
