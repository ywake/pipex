/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:40:47 by ywake             #+#    #+#             */
/*   Updated: 2020/06/30 12:17:11 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*csrc;
	size_t			i;

	csrc = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (csrc[i] == (unsigned char)c)
			return ((void *)&csrc[i]);
		i++;
	}
	return (NULL);
}
