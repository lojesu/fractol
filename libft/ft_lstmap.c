/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:05:46 by lojesu            #+#    #+#             */
/*   Updated: 2018/11/23 14:22:01 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *tmp;
	t_list *elem;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	elem = ft_lstnew(tmp->content, tmp->content_size);
	begin = elem;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		elem->next = ft_lstnew(tmp->content, tmp->content_size);
		elem = elem->next;
		lst = lst->next;
	}
	return (begin);
}
