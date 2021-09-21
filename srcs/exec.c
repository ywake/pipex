/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:23 by ywake             #+#    #+#             */
/*   Updated: 2021/09/21 17:03:11 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
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

void	exec_cmd_with_path(char *argv[], int index, char *new_argv[])
{
	int			i;
	char		**fullpaths;
	extern char	**environ;

	i = 0;
	while (environ[i])
		if (!ft_strncmp(environ[i++], "PATH=", 5))
			break ;
	fullpaths = get_fullpath(environ[i - 1], new_argv[0]);
	i = 0;
	while (fullpaths[i])
	{
		if (access(fullpaths[i], X_OK) == 0)
			exit(catch_err(execve(fullpaths[i], new_argv, environ), "execve"));
		i++;
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(argv[index], 2);
	exit(127);
}

void	exec_cmd(char *argv[], int index)
{
	char		**new_argv;
	extern char	**environ;

	new_argv = catch_nul(ft_split(argv[index], ' '), "ft_split");
	if (!ft_strchr(new_argv[0], '/'))
		exec_cmd_with_path(argv, index, new_argv);
	if (access(new_argv[0], X_OK) == 0)
		exit(catch_err(execve(new_argv[0], new_argv, environ), "execve"));
	else if (errno == ENOENT)
		pexit("pipex", 127);
	else if (errno == EACCES)
		pexit("pipex", 126);
	else
		pexit("pipex", 1);
}
