/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:01:15 by jehaenec          #+#    #+#             */
/*   Updated: 2020/01/15 17:18:13 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	ft_freegnl(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int		ft_space(char **line, char **rest, int i)
{
	if (!(*line = ft_strndup(*rest, i)))
		return (-1);
	ft_freegnl(rest);
	return (0);
}

int		ft_gnl(char **line, char **rest, int i)
{
	int		s;
	char	*cpy;

	if (i == 0 && *rest == NULL)
	{
		*line = ft_strndup("", 1);
		return (0);
	}
	s = 0;
	while ((*rest)[s] && (*rest)[s] != '\n')
		s++;
	if ((*rest)[s] == '\n')
	{
		if (!(*line = ft_strndup(*rest, s)) ||
			!(cpy = ft_substrbis(*rest, s)))
			return (-1);
		ft_freegnl(rest);
		if (!(*rest = ft_strndup(cpy, ft_strlenbis(cpy))))
			return (-1);
		free(cpy);
	}
	else if ((*rest)[s] == '\0')
		return (ft_space(line, rest, s));
	return (1);
}

int		ft_else(int fd, char *tmp, char **rest, char *buff)
{
	tmp = rest[fd];
	if (!(rest[fd] = ft_strjoinbis(rest[fd], buff)))
		return (0);
	free(tmp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			i;
	static char	*rest[OPEN_MAX];
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (rest[fd] == NULL)
		{
			if (!(rest[fd] = ft_strndup(buff, i)))
				return (-1);
		}
		else if (!(ft_else(fd, tmp, rest, buff)))
			return (-1);
		if (ft_strchrbis(rest[fd], '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	return (ft_gnl(line, &rest[fd], i));
}
