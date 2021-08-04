/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:37:26 by ywake             #+#    #+#             */
/*   Updated: 2021/08/04 12:37:27 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include <stdio.h>
#include <stdlib.h>

void	pexit(char *str)
{
	perror(str);
	exit(1);
}

int	catch_err(int status, char *msg)
{
	if (status == -1)
		pexit(msg);
	return (status);
}

void	*catch_nul(void *ptr, char *msg)
{
	if (ptr == NULL)
		pexit(msg);
	return (ptr);
}
