/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:59:31 by jehaenec          #+#    #+#             */
/*   Updated: 2020/01/15 17:39:47 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*ft_substrbis(char *s, int start);
int		ft_strchrbis(char *string, char c);
char	*ft_strndup(char *s1, int i);
char	*ft_strjoinbis(char *s1, char *s2);
int		get_next_line(int fd, char **line);
int		ft_strlenbis(char *str);
void	ft_freegnl(char **str);
#endif
