/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 03:38:59 by ywake             #+#    #+#             */
/*   Updated: 2021/06/17 22:08:45 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*new_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = ft_lstmap(lst->next, f, del);
	elem = ft_lstnew(f(lst->content));
	if (elem)
		ft_lstadd_front(&new_list, elem);
	else
		ft_lstclear(&new_list, del);
	return (elem);
}
