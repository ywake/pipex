/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap_bool_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:50:53 by ywake             #+#    #+#             */
/*   Updated: 2021/06/17 22:09:07 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strmap_bool(char const *s, int (*f)(int))
{
	unsigned int	i;
	int				rtn;

	if (s == NULL || f == NULL)
		return (-1);
	rtn = 1;
	i = 0;
	while (s[i])
	{
		rtn &= f((int)s[i]);
		i++;
	}
	return (rtn);
}
