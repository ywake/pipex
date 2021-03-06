/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:18 by ywake             #+#    #+#             */
/*   Updated: 2021/09/21 22:49:11 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "error.h"

void	redirect_in(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	catch_err(fd, filename);
	catch_err(dup2(fd, STDIN_FILENO), "dup2");
	catch_err(close(fd), "close");
}

void	redirect_out(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	catch_err(fd, filename);
	catch_err(dup2(fd, STDOUT_FILENO), "dup2");
	catch_err(close(fd), "close");
}

void	connect_pipe(int pipefd[2], int fd)
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
		return (1);
}
