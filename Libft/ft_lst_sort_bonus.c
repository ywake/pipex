/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:21:21 by ywake             #+#    #+#             */
/*   Updated: 2021/06/17 22:08:20 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstadd_back_quick(t_list **list, t_list *new, t_list **last)
{
	t_list	*next;

	next = new->next;
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	else
		(*last)->next = new;
	*last = new;
	return (next);
}

static t_list	*ft_lst_sort_re(t_list *left, int size, int (*cmp)())
{
	t_list	*ans;
	t_list	*tmp;
	t_list	*right;

	if (left == NULL || left->next == NULL)
		return (left);
	tmp = ft_lst_at(left, size / 2 - 1);
	right = tmp->next;
	tmp->next = NULL;
	left = ft_lst_sort_re(left, size / 2, cmp);
	right = ft_lst_sort_re(right, size - size / 2, cmp);
	ans = NULL;
	while (left || right)
	{
		if (left && (!right || cmp(left->content, right->content) <= 0))
			left = lstadd_back_quick(&ans, left, &tmp);
		else
			right = lstadd_back_quick(&ans, right, &tmp);
	}
	return (ans);
}

void	ft_lst_sort(t_list **list, int (*cmp)())
{
	int	size;

	size = ft_lstsize(*list);
	*list = ft_lst_sort_re(*list, size, cmp);
}
