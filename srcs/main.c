#include "pipex.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "error.h"
#include "libft.h"

#define CHILD	(0)

void	dup_pipe(int pipefd[2], int fd)
{
	exit_if_err(dup2(pipefd[fd], fd), "dup2");
	exit_if_err(close(pipefd[0]), "close");
	exit_if_err(close(pipefd[1]), "close");
}

void	child_task(int pipefd[2], int argc, char *argv[], int index)
{
	int	status;

	if (index != argc - 2)
		dup_pipe(pipefd, STDOUT_FILENO);
	else
		redirect_out(argv[argc - 1]);
	status = execvp(argv[index], ft_split(argv[index], ' '));
	exit_if_err(status, "execve");
	exit(status);
}

int	exec_cmd(int argc, char *argv[], int index, int status)
{
	int		pipefd[2];
	pid_t	pid;

	if (index == argc - 1)
		return (status);
	else if (index == 1)
		redirect_in(argv[index]);
	else
	{
		if (index != argc - 2)
			exit_if_err(pipe(pipefd), "pipe");
		pid = fork();
		if (pid == CHILD)
			child_task(pipefd, argc, argv, index);
		else
		{
			exit_if_err(pid, "fork");
			wait(&status);
			if (index != argc - 2)
				dup_pipe(pipefd, STDIN_FILENO);
		}
	}
	return (exec_cmd(argc, argv, index + 1, status));
}

int	main(int argc, char *argv[])
{
	if (argc != 5)
		return (0);
	return (exec_cmd(argc, argv, 1, 0));
}
