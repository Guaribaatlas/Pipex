#include "../inc/pipex.h"

int	ft_exit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}

int call_child(t_pipex *pipex, int *pipe_fd, char **argv, char **env)
{
	char **tmp;

	close(pipe_fd[0]);
	pipex->fd = open(argv[1], O_RDONLY);
	if (pipex->fd == -1)
		return (ft_exit("file1 open error\n"));
	if((dup2(pipex->fd, 0) == -1) || (dup2(pipe_fd[1], 1) == -1))
		return (ft_exit("dup2_child error\n"));
	close(pipex->fd);
	tmp = ft_split(argv[2], ' ');
	if (tmp[0][0] == '/')
	{
		if (execve(tmp[0], tmp, env) == -1)
			return (ft_exit("exec command error\n"));
	}
	else
	{
		if (get_path(pipex, env, tmp[0]) == -1)
			return(ft_exit("get_path error\n"));
		if (execve(pipex->cmd, tmp, env) == -1)
			return (ft_exit("exec command error\n"));
	}
	return (0);
}

int call_father(t_pipex *pipex, int *pipe_fd, char **argv, char **env)
{
	int status;
	char **tmp;

	waitpid(pipex->c_id, &status, 0);
	close(pipe_fd[1]);
	pipex->fd = open(argv[4], O_RDWR | O_CREAT, 0777);
	if (pipex->fd == -1)
		return (ft_exit("file2 open error\n"));
	if((dup2(pipe_fd[0], 0) == -1 ) || (dup2(pipex->fd, 1) == -1))
		return (ft_exit("dup2_father error\n"));
	close(pipex->fd);
	tmp = ft_split(argv[3], ' ');
	if (tmp[0][0] == '/')
	{
		if (execve(tmp[0], tmp, env) == -1)
			return (ft_exit("exec command error\n"));
	}
	else
	{
		if (get_path(pipex, env, tmp[0]) == -1)
			return(ft_exit("get_path error\n"));
		if (execve(pipex->cmd, tmp, env) == -1)
			return (ft_exit("exec command error\n"));
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	t_pipex pipex;
	int pipe_fd[2];

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
		{
			write(1, "pipe error\n", 11);
			return(-1);
		}
		pipex.c_id = fork();
		if (pipex.c_id == -1)
		{
			write(1, "fork error\n", 11);
			return (-1);
		}
		else if(pipex.c_id == 0)
		{
			printf("enfant:\n");
			return(call_child(&pipex, pipe_fd, argv, env));
		}
		else
		{
			return(call_father(&pipex, pipe_fd, argv, env));
		}
	}
	else
		write(1, "to use pipex : file1 cmd1 cmd2 file2\n", 37);
	return (0);
}