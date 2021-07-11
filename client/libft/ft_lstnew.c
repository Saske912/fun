/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 07:00:55 by pfile             #+#    #+#             */
/*   Updated: 2020/10/25 14:23:44 by sky              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*point;

	if (!(point = (t_list *)malloc(sizeof(*point))))
		return (0);
	point->content = content;
	point->next = 0;
	return (point);
}
