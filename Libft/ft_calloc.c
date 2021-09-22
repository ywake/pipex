/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 05:00:33 by ywake             #+#    #+#             */
/*   Updated: 2020/06/27 05:44:32 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;
	size_t	len;

	if (count == 0 || size == 0)
		len = 1;
	else
		len = size * count;
	rtn = (void *)malloc(len);
	if (rtn)
		ft_bzero(rtn, len);
	return (rtn);
}
