/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:18 by ywake             #+#    #+#             */
/*   Updated: 2021/08/04 12:37:19 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <fcntl.h>
#include <unistd.h>
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
