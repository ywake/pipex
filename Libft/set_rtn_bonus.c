/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rtn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:38:25 by ywake             #+#    #+#             */
/*   Updated: 2021/08/04 12:38:25 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*set_rtn(char **dest, char *source)
{
	*dest = source;
	return (source);
}

int	set_rtn_int(int *dest, int source)
{
	*dest = source;
	return (source);
}

long	set_rtn_long(long *dest, long source)
{
	*dest = source;
	return (source);
}
