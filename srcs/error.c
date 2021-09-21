/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:26 by ywake             #+#    #+#             */
/*   Updated: 2021/09/21 17:51:43 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	pexit(char *str, int status)
{
	perror(str);
	exit(status);
}

int	catch_err(int num, char *msg)
{
	if (num == -1)
		pexit(msg, 1);
	return (num);
}

void	*catch_nul(void *ptr, char *msg)
{
	if (ptr == NULL)
		pexit(msg, 1);
	return (ptr);
}

void	command_not_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": pipex: command not found", 2);
	exit(127);
}
