/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:47:03 by jehaenec          #+#    #+#             */
/*   Updated: 2021/07/27 16:47:06 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

void	do_execve(t_pipex *pipex, char **tmp, char **env)
{
	if (tmp[0][0] == '/')
	{
		if (execve(tmp[0], tmp, env) == -1)
			write(1, "execve error\n", 13);
	}
	else
	{
		if (get_path(pipex, env, tmp[0]) == -1)
			write(1, "get path error\n", 15);
		if (execve(pipex->cmd, tmp, env) == -1)
			write(1, "execve error\n", 13);
		free(pipex->cmd);
	}
}

void	ft_cmd_nfound(char *cmd)
{
	write(1, "zsh: command not found: ", 24);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
	exit(1);
}

char	**ft_mount_tmp(t_pipex *pipex, char *argv, char **env)
{
	char	**tmp;

	tmp = ft_split(argv, ' ');
	if (tmp == NULL)
		exit(1);
	pipex->args = tmp[0];
	if (tmp[0][0] == '/')
	{
		if (access(tmp[0], X_OK) == -1)
			return (NULL);
	}
	else if (get_path(pipex, env, tmp[0]) == -1)
		return (NULL);
	return (tmp);
}

int	mini_parse(char **argv, char **env)
{
	char	**tmp;
	t_pipex	tmpipex;

	tmp = ft_mount_tmp(&tmpipex, argv[2], env);
	free(tmpipex.cmd);
	if (tmp == NULL)
		ft_cmd_nfound(tmpipex.args);
	ft_free_tab(tmp);
	tmp = ft_mount_tmp(&tmpipex, argv[3], env);
	free(tmpipex.cmd);
	if (tmp == NULL)
		ft_cmd_nfound(tmpipex.args);
	ft_free_tab(tmp);
	return (1);
}
