/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 06:24:49 by ywake             #+#    #+#             */
/*   Updated: 2021/06/17 22:06:41 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	bufsize;
	size_t	i;

	bufsize = 0;
	if (ft_strlen(s) > start)
		bufsize = min(ft_strlen(s) - start, len);
	buf = (char *)malloc(sizeof(char) * (bufsize + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (i < bufsize)
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
