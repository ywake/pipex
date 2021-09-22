/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:50:53 by ywake             #+#    #+#             */
/*   Updated: 2020/12/09 03:33:01 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buf;

	if (s == NULL || f == NULL)
		return (NULL);
	i = (unsigned int)ft_strlen(s);
	buf = (char *)malloc(sizeof(char) * (i + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
