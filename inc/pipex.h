#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd;
	char	*cmd;
	char	*args;
	char	*path;
	pid_t	c_id;
}				t_pipex;

char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strlen(const char *str);
int		get_path(t_pipex *pipex, char **env, char *argv);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		mini_parse(char **argv, char **env);
void	ft_cmd_nfound(char *cmd);
char	**ft_mount_tmp(t_pipex *pipex, char *argv, char **env);
void	do_execve(t_pipex *pipex, char **tmp, char **env);
void	ft_free_tab(char **tmp);

#endif
