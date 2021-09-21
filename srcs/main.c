/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:00 by ywake             #+#    #+#             */
/*   Updated: 2021/09/21 23:28:26 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "error.h"
#include "libft.h"

#define CHILD	(0)

int	pipex(char **argv)
{
	pid_t	pid;
	int		pipefd[2];

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
	catch_err(close(pipefd[0]), "close");
	catch_err(close(pipefd[1]), "close");
	return (pid);
}

enum e_mean
{
	_,
	LAST,
	LEN
};

int	main(int argc, char *argv[])
{
	pid_t	pid[LEN];
	int		status[LEN];

	if (argc != 5)
		return (1);
	pid[LAST] = pipex(argv);
	pid[_] = 0;
	while (pid[_] >= 0)
	{
		pid[_] = waitpid(-1, &status[_], 0);
		if (pid[_] == pid[LAST])
			status[LAST] = status[_];
	}
	if (errno != ECHILD)
		pexit("pipex", 1);
	return (get_status(status[LAST]));
}
