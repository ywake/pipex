/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:26 by ywake             #+#    #+#             */
/*   Updated: 2021/09/21 17:01:31 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include <stdio.h>
#include <stdlib.h>

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
