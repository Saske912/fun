/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:38:46 by pfile             #+#    #+#             */
/*   Updated: 2020/10/18 22:22:01 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	own_commands_pipe(t_data *data)
{
	if (data->parse->delim == '|')
	{
		data->k[1] = data->n[1];
	}
}

int		own_commands_redirect(t_data *data)
{
	t_parse *tmp;
	int		k;

	tmp = data->parse;
	k = 1;
	while (k)
	{
		k = 0;
		if (tmp->delim == '>')
			redir_own_one(&tmp, data, &k);
		else if (tmp->delim == '#')
			redir_own_two(&tmp, data, &k);
		else if (tmp->delim == '<')
		{
			ft_putstr_fd("minishell: error: build-in command with \'<\'\n", 2);
			return (1);
		}
	}
	return (0);
}

void	check_command(t_data *data)
{
	t_parse	*tmp;
	t_list	*tmp2;

	data->rd_count = 0;
	data->error_code = 0;
	if (own_commands_redirect(data))
		return ;
	own_commands_pipe(data);
	redir_own_in_funcs(data);
	if (data->parse->delim == '#' || data->parse->delim == '>')
	{
		close(data->k[1]);
		data->k[1] = 1;
		tmp = data->parse;
		while (data->rd_count--)
		{
			tmp2 = tmp->param;
			while (-1 + tmp->lstlen--)
				tmp2 = tmp2->next;
			tmp2->next = NULL;
			tmp = tmp->next;
		}
	}
}

void	check_loop(t_counter *c, t_data *data, char **str, char **counter)
{
	while ((*counter)[c->len])
	{
		if (parse_cmp(" \t", (*counter)[c->len]) && parse_ok(c->i, c->k))
		{
			while (parse_cmp(" \t", (*counter)[c->len]))
				c->len++;
			c->len--;
			break ;
		}
		if ((*counter)[c->len] == '\'' && !(c->k % 2))
			c->i++;
		else if ((*counter)[c->len] == '\"' && !(c->i % 2))
			c->k++;
		if (!(c->i % 2) && (*counter)[c->len] == '$')
		{
			get_env(counter, c, data);
			c->len--;
			continue ;
		}
		c->len++;
	}
	parse_comand(str, *counter, c, " \t");
}

void	check_bracket(char **str, int i, int k, t_data *data)
{
	t_br	t;

	t.n = 0;
	t.b = 0;
	t.i = i;
	t.k = k;
	if (!*str)
		return ;
	t.len = (int)ft_strlen(*str) - i - k + 1;
	if (t.len <= 1)
	{
		free(*str);
		if (!(*str = ft_strdup("")))
			error_standart(NULL);
		return ;
	}
	if (!(t.new_str = (char *)ft_calloc(t.len, sizeof(char))))
		error_standart(NULL);
	data->parse->one_q = 0;
	data->parse->two_q = 0;
	bracket_loop(str, &t, data);
	t.new_str[t.n] = '\0';
	free(*str);
	*str = t.new_str;
}
