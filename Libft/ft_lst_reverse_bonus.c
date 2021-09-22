/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:35:06 by ywake             #+#    #+#             */
/*   Updated: 2021/06/17 22:09:28 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_reverse(t_list **lst)
{
	t_list	*first_one;
	t_list	*ans;

	ans = NULL;
	while (*lst)
	{
		first_one = (*lst);
		*lst = (*lst)->next;
		first_one->next = NULL;
		ft_lstadd_front(&ans, first_one);
	}
	*lst = ans;
}
