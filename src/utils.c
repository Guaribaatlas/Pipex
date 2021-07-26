#include "../inc/pipex.h"

char  *check_path(t_pipex *pipex, char *cmd)
{
	char **tmp;
	int i;
	char *cmd_tmp;

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
			break;
	}
	ft_freegnl(tmp);
	free(cmd_tmp);
	return (cmd);
}

int	get_path(t_pipex *pipex, char **env, char *cmd)
{
	int i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
		{
			pipex->path = ft_strdup(env[i]);
			if (!(pipex->path))
				return (-1);
			break;
		}
	}
	while (*pipex->path != '=')
		pipex->path++;
	pipex->path++;
	pipex->cmd = check_path(pipex, cmd);
	if (pipex->cmd)
		return(0);
	return (-1);
}