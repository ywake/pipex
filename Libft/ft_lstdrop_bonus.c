/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdrop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:39:04 by ywake             #+#    #+#             */
/*   Updated: 2021/08/04 12:39:04 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief A function that finds the element [drop] in the list [head]
 * and deletes it using [del].
 */
void	ft_lstdrop(t_list **head, t_list *drop, void (*del)(void *))
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = *head;
	while (cur)
	{
		if (cur == drop)
		{
			if (prev == NULL)
				*head = drop->next;
			else
				prev->next = drop->next;
			return (ft_lstdelone(drop, del));
		}
		prev = cur;
		cur = cur->next;
	}
}
