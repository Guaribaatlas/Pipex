/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:45:55 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/13 13:22:18 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		n;

	n = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (0);
	ft_strcpy(dup, s1);
	return (dup);
}
