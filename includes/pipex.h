/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:50 by ywake             #+#    #+#             */
/*   Updated: 2021/09/21 17:12:27 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>

void	redirect_in(char *filename);
void	redirect_out(char *filename);
void	exec_cmd(char *argv[], int index);
void	connect_pipe(pid_t pipefd[2], int fd);
int		get_status(int	status);

#endif
