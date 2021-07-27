/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:58:05 by jehaenec          #+#    #+#             */
/*   Updated: 2021/07/26 17:58:07 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_free_tab(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
}

char	*check_path(t_pipex *pipex, char *cmd)
{
	char	**tmp;
	int		i;
	char	*cmd_tmp;

	tmp = ft_split(pipex->path, ':');
	if (!(tmp))
		return (NULL);
	i = -1;
	cmd_tmp = ft_strjoin("/", cmd);
	while (tmp[++i])
	{
		cmd = ft_strjoin(tmp[i], cmd_tmp);
		if (cmd == NULL)
			return (NULL);
		if (access(cmd, X_OK) == 0)
			break ;
	}
	if (access(cmd, X_OK) == -1)
		return (NULL);
	ft_free_tab(tmp);
	free(cmd_tmp);
	return (cmd);
}

int	get_path(t_pipex *pipex, char **env, char *cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
		{
			pipex->path = ft_strdup(env[i]);
			if (!(pipex->path))
				return (-1);
			break ;
		}
	}
	tmp = pipex->path;
	while (*pipex->path != '=')
		pipex->path++;
	pipex->path++;
	pipex->cmd = check_path(pipex, cmd);
	free(tmp);
	if (pipex->cmd)
		return (0);
	return (-1);
}
