/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:36:28 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/10 17:47:20 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*p;

	if (!s1 || !s2 || !(dst = (char *)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
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
