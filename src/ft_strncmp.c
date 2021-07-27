/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:07:30 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/09 16:20:49 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c1;
	unsigned int	c2;

	while (n > 0)
	{
		c1 = *s1;
		c2 = *s2;
		if (c1 != c2)
			return ((unsigned char)c1 - (unsigned char)c2);
		if (c1 == 0)
			return (0);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
