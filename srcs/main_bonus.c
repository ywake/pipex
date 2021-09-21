/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:00 by ywake             #+#    #+#             */
/*   Updated: 2021/09/21 18:26:32 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "error.h"
#include "libft.h"

#define CHILD	(0)

int	main(int argc, char *argv[])
{
	int		index;
	int		status;
	pid_t	pid;
	pid_t	pipefd[2][2];

	if (argc < 5)
		return (1);
	index = 1;
	while (++index < argc - 1)
	{
		if (index != argc - 2)
			catch_err(pipe(pipefd[index % 2]), "pipe");
		pid = catch_err(fork(), "fork");
		if (pid == CHILD)
		{
			if (index == 2)
				redirect_in(argv[1]);
			else
				connect_pipe(pipefd[!(index % 2)], STDIN_FILENO);
			if (index == argc - 2)
				redirect_out(argv[argc - 1]);
			else
				connect_pipe(pipefd[index % 2], STDOUT_FILENO);
			exec_cmd(argv, index);
		}
		if (index != 2)
		{
			catch_err(close(pipefd[!(index % 2)][0]), "close");
			catch_err(close(pipefd[!(index % 2)][1]), "close");
		}
	}
	while (pid >= 0)
		pid = waitpid(-1, &status, 0);
	if (errno != ECHILD)
		pexit("pipex", 1);
	return (get_status(status));
}
