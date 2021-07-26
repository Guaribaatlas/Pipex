/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:59:40 by jehaenec          #+#    #+#             */
/*   Updated: 2020/01/15 17:48:31 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int		ft_strlenbis(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int		ft_strchrbis(char *string, char c)
{
	while (*string)
	{
		if (*string == c)
			return (1);
		string++;
	}
	return (0);
}

char	*ft_substrbis(char *s, int start)
{
	char	*new;
	char	*tmp;
	int		d;

	d = ft_strlenbis(s);
	if (s[start] == '\n')
		start++;
	if (start >= d)
		return (ft_strndup("", 1));
	if (!(new = (char *)malloc(sizeof(char) * ((d - start) + 1))))
		return (NULL);
	tmp = new;
	s += start;
	while (*s)
	{
		*new = *s;
		new++;
		s++;
	}
	*new = '\0';
	return (tmp);
}

char	*ft_strndup(char *s1, int i)
{
	char	*dup;
	char	*ret;
	int		s;

	s = ft_strlenbis(s1);
	if (s < i)
	{
		if (!(dup = (char *)malloc(sizeof(char) * (s + 1))))
			return (0);
		dup[s] = '\0';
	}
	else
	{
		if (!(dup = (char *)malloc(sizeof(char) * (i + 1))))
			return (0);
		dup[i] = '\0';
	}
	ret = dup;
	if (s != 0)
		while (i != 0 && *s1 != '\0')
		{
			*dup++ = *s1++;
			i--;
		}
	return (ret);
}

char	*ft_strjoinbis(char *s1, char *s2)
{
	char	*dst;
	char	*p;

	if (!s2 || !(dst = (char *)malloc(sizeof(char) * (ft_strlenbis(s1) +
						ft_strlenbis(s2) + 1))))
		return (NULL);
	p = dst;
	while (*s1)
	{
		*dst = *(char *)s1++;
		dst++;
	}
	while (*s2)
	{
		*dst = *(char *)s2++;
		dst++;
	}
	*dst = 0;
	return (p);
}
