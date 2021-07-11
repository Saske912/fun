/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:04:39 by pfile             #+#    #+#             */
/*   Updated: 2020/10/18 21:02:37 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_low_case(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = ft_strdup(data->parse->head->content)))
		error_standart(NULL);
	ft_strlowcase(str);
	if (!(strcmp(str, EXP))
		|| !(strcmp(str, CD))
		|| !(strcmp(str, EXI))
		|| !(strcmp(str, UNS)))
		i = 1;
	free(str);
	if (i == 0)
	{
		ft_strlowcase(data->parse->head->content);
	}
}

int		parse_argv_loop(t_argv *a, t_data *data)
{
	a->c.start = a->c.len;
	check_loop(&a->c, data, &a->str, &a->counter);
	data->parse->str = a->counter;
	check_bracket(&a->str, a->c.i, a->c.k, data);
	a->list = ft_lstnew(a->str);
	if (!a->flag)
	{
		a->flag = 1;
		data->parse->head = a->list;
	}
	ft_lstadd_back(&a->head, a->list);
	a->c.len++;
	if (a->c.i % 2 || a->c.k % 2)
	{
		ft_putstr("Error: quote's\n");
		return (-1);
	}
	a->c.i = 0;
	a->c.k = 0;
	return (0);
}

int		parse_argv(t_data *data)
{
	t_argv	a;

	a.flag = 0;
	a.counter = data->parse->str;
	parse_init(&a.c, a.counter);
	a.head = NULL;
	while (a.c.len < a.c.strlen)
		if (parse_argv_loop(&a, data) == -1)
			return (-1);
	data->parse->param = a.head;
	return (0);
}
