/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:39:57 by ywake             #+#    #+#             */
/*   Updated: 2021/06/17 22:43:21 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static int	get_digit(int n)
{
	int	digit;

	digit = (n <= 0);
	while (n)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		digit;
	int		sign;
	char	*buf;

	sign = 1 - 2 * (n < 0);
	digit = get_digit(n);
	buf = (char *)malloc(sizeof(char) * (digit + 1));
	if (buf == NULL)
		return (NULL);
	buf[digit] = '\0';
	while (digit > 0)
	{
		if (n == 0 && sign < 0)
			buf[--digit] = '-';
		else
			buf[--digit] = n % 10 * sign + '0';
		n /= 10;
	}
	return (buf);
}
