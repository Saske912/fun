/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:07:30 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/15 14:01:22 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_specials(int *flag, t_list **tmp, int breaker, t_data *data)
{
	if (*flag == 0 && !ft_strcmp((*tmp)->content, "-n"))
	{
		*flag = 1;
		(*tmp) = (*tmp)->next;
		return (1);
	}
	if (((char *)(*tmp)->content)[0] == '\0')
	{
		if (breaker > 0 && (*tmp)->next \
				&& ((char *)(*tmp)->next->content)[0] != '\0')
			ft_putstr_fd(" ", data->k[1]);
		(*tmp) = (*tmp)->next;
		return (1);
	}
	return (0);
}

int		ft_echo(t_list *param, t_data *data)
{
	int		flag;
	int		breaker;
	t_list	*tmp;

	flag = 0;
	breaker = 0;
	tmp = param->next;
	while (tmp)
	{
		if (ft_check_specials(&flag, &tmp, breaker, data))
			continue ;
		ft_putstr_fd(tmp->content, data->k[1]);
		if (tmp->next && ((char *)tmp->next->content)[0] != '\0')
			ft_putstr_fd(" ", data->k[1]);
		breaker++;
		tmp = tmp->next;
	}
	if (flag == 0)
		ft_putstr_fd("\n", data->k[1]);
	return (0);
}
