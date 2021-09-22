/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:41:22 by ywake             #+#    #+#             */
/*   Updated: 2021/06/17 22:44:47 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*itoa(int n, char *buf)
{
	int		digit;
	int		sign;

	sign = 1 - 2 * (n < 0);
	digit = get_digit(n);
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

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];

	ft_bzero(buf, 12);
	itoa(n, buf);
	ft_putstr_fd(buf, fd);
}
