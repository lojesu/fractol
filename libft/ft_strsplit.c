/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:40:27 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/23 16:43:38 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if ((s[i + 1] == c && s[i] != c) || (s[i + 1] == '\0'))
				count++;
			i++;
		}
	}
	return (count);
}

static char	**ft_fill_tab(char **tab, char c, char const *s)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s[k] != '\0' && i < ft_count_word(s, c))
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != '\0' && s[k] != c)
		{
			tab[i][j] = s[k];
			k++;
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static char	**ft_str_malloc(char const *s, char c)
{
	int			i;
	int			j;
	int			k;
	char		**tab;

	i = 0;
	k = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (0);
	while (i < ft_count_word(s, c))
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k] != '\0')
		{
			j++;
			k++;
		}
		if (!(tab[i] = (char*)malloc(sizeof(char) * j + 1)))
			return (0);
		i++;
	}
	return (ft_fill_tab(tab, c, s));
}

char		**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (0);
	return (ft_str_malloc(s, c));
}
