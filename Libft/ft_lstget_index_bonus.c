/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_index_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:38:46 by ywake             #+#    #+#             */
/*   Updated: 2021/08/04 12:38:47 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Find [target] in the list starting from [head].
 * @return If [target] is found, its index is returned, and if it is not found,
 * the length of the list is returned.
 */
size_t	ft_lstget_index(t_list *head, t_list *target)
{
	size_t	i;

	i = 0;
	while (head)
	{
		if (head == target)
			return (i);
		i++;
		head = head->next;
	}
	return (i);
}
