/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:16:38 by pfile             #+#    #+#             */
/*   Updated: 2020/10/29 16:47:02 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pull_tainer_check_loop(int *k, t_parse **tmp, t_data *data)
{
	while (*k)
	{
		*k = 0;
		ft_check_dollar_question(tmp, data);
		if (tmp && parse_cmp("<>#", (*tmp)->delim))
		{
			*tmp = (*tmp)->next;
			data->nod++;
			*k = 1;
		}
	}
}

void	pull_util(t_parse *tmp, t_data *data)
{
	int		res;
	pid_t	cycle;
	int		status;

	if (!tmp)
		return ;
	if (tmp->delim == '|')
		pipe(data->n);
	if (data->parse->param &&\
	(res = get_no_shell(data->parse->param->content)) == -1)
		return ;
	else if (!res)
		check_command(data);
	else
	{
		cycle = fork();
		if (cycle == 0 && !init_dirs(data->envp, data->parse->param, data))
			return ;
		else if (cycle < 0)
			error_standart(data);
		waitpid(cycle, &status, WUNTRACED);
		ft_exitcode(status, data);
	}
}

int		parse_string(t_counter *c, char *str, t_data *data)
{
	while (1)
	{
		if (str[c->len] == '\'' && !c->k)
			c->i++;
		else if (str[c->len] == '\"' && !c->i)
			c->k++;
		if (parse_util_breaker(str, c, data) == 1)
			break ;
		c->len++;
	}
	data->counter = *c;
	if (*(data->parse->str) == '\0')
	{
		ft_putstr("minishell: syntax error near unexpected token\n");
		return (-1);
	}
	if (parse_argv(data) == -1)
		return (-1);
	return (0);
}

void	maintainer(t_counter *c, char *str, t_data *data)
{
	t_parse *tmp;

	tmp = data->parse;
	while (c->len < (int)c->strlen)
	{
		c->start = c->len;
		if (parse_string(c, str, data) == -1)
			return ;
		if (!c->end && c->len + 1 < c->strlen)
		{
			data->parse->next = ft_parsenew();
			data->parse = data->parse->next;
		}
		else if (data->parse->delim == '>' || data->parse->delim == '<'
			|| data->parse->delim == '#')
			error_specials("newline", 0, data);
		c->len++;
	}
	pull_tainer(tmp, data);
}

void	parse_arg(t_data *data)
{
	t_counter		c;

	data->parse = ft_parsenew();
	data->head = data->parse;
	data->nod = 0;
	g_read_started = 0;
	parse_init(&c, data->str);
	maintainer(&c, data->str, data);
}
