/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 08:10:20 by ywake             #+#    #+#             */
/*   Updated: 2020/09/07 17:20:54 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buf;
	size_t	i;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL)
		i++;
	len = ft_strlen(&s1[i]);
	if (len > 0)
		while (ft_strchr(set, s1[i + len - 1]) != NULL)
			len--;
	buf = ft_substr(s1, i, len);
	return (buf);
}
