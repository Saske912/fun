/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_own.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:43:19 by pfile             #+#    #+#             */
/*   Updated: 2020/10/29 15:43:21 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_own_in_funcs(t_data *data)
{
	if (!strcmp(data->parse->param->content, ECHO))
		data->error_code = ft_echo(data->parse->param, data);
	else if (!strcmp(data->parse->param->content, PWD))
		data->error_code = ft_pwd(data);
	else if (!strcmp(data->parse->param->content, CD))
		data->error_code = ft_cd(data);
	else if (!strcmp(data->parse->param->content, ENV))
		data->error_code = ft_env(data->env_var, data);
	else if (!strcmp(data->parse->param->content, EXP))
		data->error_code = ft_export(data);
	else if (!strcmp(data->parse->param->content, UNS))
		data->error_code = ft_unset(data);
	else if (!strcmp(data->parse->param->content, EXI))
		data->error_code = ft_exit(data);
	else
		error_command(data->parse->param, "command not found", data);
}

void	redir_own_one(t_parse **tmp, t_data *data, int *k)
{
	data->rd_count++;
	(*tmp)->lstlen = ft_lstsize((*tmp)->param);
	*tmp = (*tmp)->next;
	if ((data->k[1] = open((char *)(*tmp)->param->content, RDWR)) == -1)
	{
		error_standart(data);
	}
	ft_lstadd_back(&data->parse->head, (*tmp)->head->next);
	if (parse_cmp(">#", (*tmp)->delim))
		close(data->k[1]);
	*k = 1;
}

void	redir_own_two(t_parse **tmp, t_data *data, int *k)
{
	data->rd_count++;
	(*tmp)->lstlen = ft_lstsize((*tmp)->param);
	*tmp = (*tmp)->next;
	if ((data->k[1] = open((char *)(*tmp)->param->content, RDWRE)) == -1)
		error_standart(data);
	ft_lstadd_back(&data->parse->head, (*tmp)->head->next);
	if (parse_cmp(">#", (*tmp)->delim))
		close(data->k[1]);
	*k = 1;
}
