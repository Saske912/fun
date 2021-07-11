/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:42:52 by pfile             #+#    #+#             */
/*   Updated: 2020/10/18 21:40:27 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pull_pipe(t_data *data, char delim)
{
	if (!parse_cmp("#>", delim))
		dup2(data->n[1], 1);
	return (0);
}

int		pull_end_out(t_data *data, char *delim, t_search *s, int *k)
{
	*delim = data->parse->delim;
	data->parse = data->parse->next;
	s->list = data->parse->param;
	if ((data->k[1] = open((char *)s->list->content, RDWRE)) == -1)
	{
		error_standart(data);
		return (1);
	}
	s->list = s->list->next;
	if (data->parse->delim != *delim)
		dup2(data->k[1], 1);
	close(data->k[1]);
	*k = 1;
	return (0);
}

int		pull_out(t_data *data, char *delim, t_search *s, int *k)
{
	*delim = data->parse->delim;
	data->parse = data->parse->next;
	s->list = data->parse->param;
	if ((data->k[1] = open((char *)s->list->content, RDWR)) == -1)
	{
		error_standart(data);
		return (1);
	}
	s->list = data->parse->param->next;
	if (data->parse->delim != *delim)
		dup2(data->k[1], 1);
	close(data->k[1]);
	*k = 1;
	return (0);
}

int		pull_in(t_data *data, char *delim, t_search *s, int *k)
{
	*delim = data->parse->delim;
	data->parse = data->parse->next;
	s->list = data->parse->param;
	if ((data->k[0] = open((char *)s->list->content, RD)) == -1)
	{
		error_standart(data);
		return (1);
	}
	s->list = data->parse->param->next;
	if (data->parse->delim != *delim)
		dup2(data->k[0], 0);
	close(data->k[0]);
	*k = 1;
	return (0);
}

void	pull_tainer(t_parse *tmp, t_data *data)
{
	int		k;

	while (tmp)
	{
		k = 1;
		data->parse = tmp;
		data->nod = 0;
		if (tmp->param && ((char *)data->parse->param->content)[0] != '.')
			parse_low_case(data);
		pull_tainer_check_loop(&k, &tmp, data);
		pull_util(tmp, data);
		if ('|' == tmp->delim)
		{
			dup2(data->n[0], 0);
			close(data->n[0]);
			close(data->n[1]);
		}
		else if (';' == tmp->delim)
			dup2(data->fd_src, 0);
		tmp = tmp->next;
	}
	dup2(data->fd_src, 0);
	dup2(data->fd_dst, 1);
	data->k[0] = 0;
	data->k[1] = 1;
}
