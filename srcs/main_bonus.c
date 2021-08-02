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

int	parent_task(pid_t c_pid, int pipefd[2], int argc, int index)
{
	int	status;

	catch_err(waitpid(c_pid, &status, WNOHANG), "waitpid");
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

int	arg_loop(int argc, char *argv[], int index)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (index != argc - 2)
		catch_err(pipe(pipefd), "pipe");
	pid = catch_err(fork(), "fork");
	if (pid == CHILD)
	{
		if (index == 2)
			redirect_in(argv[1]);
		if (index != argc - 2)
			dup_pipe(pipefd, STDOUT_FILENO);
		else
			redirect_out(argv[argc - 1]);
		exec_cmd(argv, index);
	}
	else
		status = parent_task(pid, pipefd, argc, index);
	if (index == argc - 2)
		return (status);
	return (arg_loop(argc, argv, index + 1));
}

int	main(int argc, char *argv[])
{
	int	status;
	int	status2;

	if (argc < 5)
		return (0);
	status = arg_loop(argc, argv, 2);
	while (waitpid(-1, &status2, 0) > 0)
		;
	return (status);
}
