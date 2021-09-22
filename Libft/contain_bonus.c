/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contain_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:38:30 by ywake             #+#    #+#             */
/*   Updated: 2021/08/04 12:38:31 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief A function that searches for [str] in a [array].
 * @return Returns the index if found, -1 if not found.
 */
int	contain(char **array, char *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!ft_strncmp(array[i], str, -1))
			return (i);
		i++;
	}
	return (-1);
}
