/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:07:56 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/29 22:27:28 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_utils_if(char **envp, t_dirs *d, t_data *data)
{
	if (!envp[d->i] && (parse_cmp("./",\
	((char *)data->parse->param->content)[0])))
	{
		d->p = 0;
		d->flag = 1;
		while (((char *)data->parse->param->content)[d->p])
		{
			if (((char *)data->parse->param->content)[d->p] == '/')
				d->slsh = d->p;
			d->p++;
		}
		if (!(d->buf2 = ft_strndup((char *)\
		data->parse->param->content, d->slsh)))
			error_standart(NULL);
		if (!(d->path = ft_split(d->buf2, ':')))
			error_standart(data);
		free(d->buf2);
	}
}

void	init_utils_error(t_data *data, t_list *list)
{
	error_command(list, "No such file or directory", data);
	exit(127);
}

void	init_relative_path(t_dirs *d, char **envp, t_data *data)
{
	while (d->equal[d->len])
	{
		if (d->equal[d->len] == '/')
			d->slsh = d->len;
		d->len++;
	}
	if (d->slsh && !(d->buf = ft_strndup(d->equal, d->slsh)))
		error_standart(NULL);
	if (!(d->dirs = ft_strjoin(&envp[d->i][5], ":")))
		error_standart(data);
	if (!(d->buf2 = ft_strjoin(d->dirs, d->buf)))
		error_standart(data);
	free(d->dirs);
	free(d->buf);
}

void	init_dirs_struct(t_data *data, t_dirs *d)
{
	d->i = 0;
	d->flag = 0;
	d->len = 0;
	d->slsh = 0;
	d->buf = NULL;
	d->equal = data->parse->param->content;
}

int		init_delim_check(t_data *data, t_search *s, int *k)
{
	char	delim;

	delim = 0;
	if (data->parse->delim == '>' && pull_out(data, &delim, s, k))
		return (1);
	if (data->parse->delim == '<' && pull_in(data, &delim, s, k))
		return (1);
	if (data->parse->delim == '#' && pull_end_out(data, &delim, s, k))
		return (1);
	if (data->parse->delim == '|' && pull_pipe(data, delim))
		return (1);
	return (0);
}
