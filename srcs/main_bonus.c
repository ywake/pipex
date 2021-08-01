#include "pipex.h"

#include <unistd.h>
#include <sys/wait.h>
#include "error.h"
#include "libft.h"

#define CHILD	(0)

void	dup_pipe(int pipefd[2], int fd)
{
	catch_err(dup2(pipefd[fd], fd), "dup2");
	catch_err(close(pipefd[0]), "close");
	catch_err(close(pipefd[1]), "close");
}

int	parent_task(int pipefd[2], int argc, int index)
{
	int	status;

	wait(&status);
	if (index != argc - 2)
		dup_pipe(pipefd, STDIN_FILENO);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else if (WIFSTOPPED(status))
		return (WSTOPSIG(status));
	else
		return (EXIT_FAILURE);
}

int	arg_recur(int argc, char *argv[], char *envp[], int index)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (index == 1)
		redirect_in(argv[index]);
	else
	{
		if (index != argc - 2)
			catch_err(pipe(pipefd), "pipe");
		pid = catch_err(fork(), "fork");
		if (pid == CHILD)
		{
			if (index != argc - 2)
				dup_pipe(pipefd, STDOUT_FILENO);
			else
				redirect_out(argv[argc - 1]);
			exec_cmd(argv, envp, index);
		}
		else
			status = parent_task(pipefd, argc, index);
	}
	if (index == argc - 2)
		return (status);
	return (arg_recur(argc, argv, envp, index + 1));
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		return (0);
	return (arg_recur(argc, argv, envp, 1));
}
