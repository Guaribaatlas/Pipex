/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:48:01 by jehaenec          #+#    #+#             */
/*   Updated: 2021/06/05 15:48:03 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**ft_free(char **tab, int z)
{
	while (z >= 0)
	{
		free(tab[z]);
		z--;
	}
	free(tab);
	return (NULL);
}

static char	**ft_mallword(char *str, char **tab, char c)
{
	char	*tmp;
	int		m;
	int		z;

	z = 0;
	tmp = str;
	m = 0;
	while (*tmp)
	{
		if (*tmp != c)
			m++;
		if (*tmp == c && m > 0)
		{
			tab[z] = (char *)malloc(sizeof (char) * (m + 1));
			if (tab[z] == NULL)
				return (ft_free(tab, z - 1));
			m = 0;
			z++;
		}
		tmp++;
	}
	tab[z] = (char *)malloc(sizeof (char) * (m + 1));
	if (tab[z] == NULL)
		return (ft_free(tab, z - 1));
	return (tab);
}

static char	**ft_mktab(char *str, char **tab, char c)
{
	char	*tmp;
	int		z;
	int		m;
	int		i;

	tmp = str;
	z = 0;
	i = 0;
	while (*tmp)
	{
		if (*tmp != c)
		{
			tab[z][i++] = *tmp;
			m = 1;
		}
		if (*tmp++ == c && m != 0)
		{
			tab[z++][i] = '\0';
			m = 0;
			i = 0;
		}
	}
	tab[z][i] = '\0';
	return (tab);
}

char	**ft_split(const char *str, char c)
{
	char	**tab;
	char	*split;
	int		i;
	int		count;

	if (!str)
		return (NULL);
	split = ft_strtrim(str, &c);
	if (split == NULL)
		return (NULL);
	count = 0;
	i = -1;
	while (split[++i])
	{
		if (split[i] != c && (split[i + 1] == c || split[i + 1] == '\0'))
			count++;
	}
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (tab == NULL)
		return (0);
	tab = ft_mallword(split, tab, c);
	tab = ft_mktab(split, tab, c);
	tab[count] = 0;
	free(split);
	return (tab);
}
