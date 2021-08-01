#include "pipex.h"

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "error.h"

char	**get_fullpath(char *path, char *cmd)
{
	char	**paths;
	int		i;

	paths = catch_nul(ft_split(path, ':'), "ft_split");
	i = 0;
	while (paths[i])
	{
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
			free_set((void **)&paths[i],
				catch_nul(ft_strjoin(paths[i], "/"), "ft_strjoin"));
		free_set((void **)&paths[i],
			catch_nul(ft_strjoin(paths[i], cmd), "ft_strjoin"));
		i++;
	}
	return (paths);
}

void	exec_cmd_with_path(
	char *argv[], char *envp[], int index, char *new_argv[])
{
	int		i;
	char	**fullpaths;

	i = 0;
	while (envp[i])
		if (!ft_strncmp(envp[i++], "PATH=", 5))
			break ;
	fullpaths = get_fullpath(envp[i - 1], new_argv[0]);
	i = 0;
	while (fullpaths[i])
	{
		if (access(fullpaths[i], X_OK) == 0)
			exit(catch_err(execve(fullpaths[i], new_argv, envp), "execve"));
		i++;
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(argv[index], 2);
	exit(127);
}

void	exec_cmd(char *argv[], char *envp[], int index)
{
	char	**new_argv;

	new_argv = catch_nul(ft_split(argv[index], ' '), "ft_split");
	if (!ft_strchr(new_argv[0], '/'))
		exec_cmd_with_path(argv, envp, index, new_argv);
	if (catch_err(access(new_argv[0], X_OK), new_argv[0]) == 0)
		exit(catch_err(execve(new_argv[0], new_argv, envp), "execve"));
}
