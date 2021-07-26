/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:18:19 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/23 11:09:45 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = 0;
	return (dest);
}
