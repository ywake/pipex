/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:29:06 by ywake             #+#    #+#             */
/*   Updated: 2020/06/30 12:15:15 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == (unsigned char)c)
			return (&cdst[i + 1]);
		i++;
	}
	return (NULL);
}
