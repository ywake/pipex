/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:00 by ywake             #+#    #+#             */
/*   Updated: 2021/08/04 12:37:01 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "error.h"
#include "libft.h"

#define CHILD	(0)

void	connect_pipe(pid_t pipefd[2], int fd)
{
	catch_err(dup2(pipefd[fd], fd), "dup2");
	catch_err(close(pipefd[0]), "close");
	catch_err(close(pipefd[1]), "close");
}

int	get_status(int	status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else if (WIFSTOPPED(status))
		return (WSTOPSIG(status));
	else
		return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int		status;
	pid_t	pid;
	pid_t	pipefd[2];

	if (argc != 5)
		return (1);
	catch_err(pipe(pipefd), "pipe");
	pid = catch_err(fork(), "fork");
	if (pid == CHILD)
	{
		redirect_in(argv[1]);
		connect_pipe(pipefd, STDOUT_FILENO);
		exec_cmd(argv, 2);
	}
	pid = catch_err(fork(), "fork");
	if (pid == CHILD)
	{
		redirect_out(argv[4]);
		connect_pipe(pipefd, STDIN_FILENO);
		exec_cmd(argv, 3);
	}
	while (pid >= 0)
		pid = waitpid(-1, &status, 0);
	if (errno != ECHILD)
		pexit("pipex");
	return (get_status(status));
}
