/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 19:10:06 by pfile             #+#    #+#             */
/*   Updated: 2020/05/20 09:13:42 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*st;
	t_list	*res;
	void	*counter;

	if (!(void *)lst)
		return (0);
	counter = f(lst->content);
	if (!(st = ft_lstnew(counter)))
	{
		del(counter);
		return (0);
	}
	res = st;
	while ((lst = lst->next))
	{
		counter = f(lst->content);
		if (!(st->next = ft_lstnew(counter)))
		{
			del(counter);
			ft_lstclear(&res, del);
			return (0);
		}
		st = st->next;
	}
	return (res);
}
