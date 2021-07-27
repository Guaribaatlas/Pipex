/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:58:11 by jehaenec          #+#    #+#             */
/*   Updated: 2021/07/26 17:58:13 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_exit(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

int	check_open(char *file)
{
	char	*str;
	char	*ret;

	str = strerror(errno);
	ret = ft_strjoin(file, " : ");
	if (ret == NULL)
		exit (1);
	str = ft_strjoin(ret, str);
	if (str == NULL)
		exit (1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

int	call_child(t_pipex *pipex, int *pipe_fd, char **argv, char **env)
{
	char	**tmp;

	close(pipe_fd[0]);
	pipex->fd = open(argv[1], O_RDONLY);
	if (pipex->fd == -1)
		return (check_open(argv[1]));
	if ((dup2(pipex->fd, 0) == -1) || (dup2(pipe_fd[1], 1) == -1))
		return (ft_exit("dup2_child error\n"));
	close(pipex->fd);
	tmp = ft_split(argv[2], ' ');
	if (tmp == NULL)
		return (ft_exit("split fail\n"));
	else
		do_execve(pipex, tmp, env);
	ft_free_tab(tmp);
	return (0);
}

int	call_father(t_pipex *pipex, int *pipe_fd, char **argv, char **env)
{
	int		status;
	char	**tmp;

	waitpid(pipex->c_id, &status, 0);
	close(pipe_fd[1]);
	pipex->fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pipex->fd == -1)
		return (check_open(argv[4]));
	if ((dup2(pipe_fd[0], 0) == -1 ) || (dup2(pipex->fd, 1) == -1))
		return (ft_exit("dup2_father error\n"));
	close(pipex->fd);
	tmp = ft_split(argv[3], ' ');
	if (tmp == NULL)
		return (-1);
	do_execve(pipex, tmp, env);
	ft_free_tab(tmp);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		pipe_fd[2];

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
		{
			write(1, "pipe error\n", 11);
			return (-1);
		}
		if (mini_parse(argv, env))
		{
			pipex.c_id = fork();
			if (pipex.c_id == -1)
				write(1, "fork error\n", 11);
			else if (pipex.c_id == 0)
				return (call_child(&pipex, pipe_fd, argv, env));
			else
				return (call_father(&pipex, pipe_fd, argv, env));
		}
	}
	else
		write(1, "to use pipex : file1 cmd1 cmd2 file2\n", 37);
	return (0);
}
