/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:01:48 by pfile             #+#    #+#             */
/*   Updated: 2020/10/25 13:42:47 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		init_loop(t_search *s, t_data *data)
{
	int		k;
	t_list	*list;
	int		counter;

	k = 1;
	while (k)
	{
		k = 0;
		list = data->parse->param;
		counter = ft_lstsize(list);
		if (s->lst < counter)
		{
			while (s->lst < counter)
			{
				s->args[s->lst] = (char *)s->list->content;
				s->list = s->list->next;
				s->lst++;
			}
			s->args[s->lst] = NULL;
		}
		if (init_delim_check(data, s, &k))
			return (1);
	}
	return (0);
}

int		init_dir_loop(t_search *s, char **envp, t_data *data, char **path)
{
	int		status;

	if (!strcmp(s->dir->d_name, (char *)s->list->content))
	{
		if (!(s->exec_path = ft_strjoin(path[s->path_count], "/")))
			error_standart(data);
		if (!(s->exec = ft_strjoin(s->exec_path, (char *)s->list->content)))
			error_standart(data);
		free(s->exec_path);
		s->args[0] = ft_strdup(s->exec);
		s->lst = 1;
		s->list = s->list->next;
		if (!init_loop(s, data))
		{
			status = execve(s->exec, s->args, envp);
			exit(status);
		}
		else
			return (1);
	}
	return (0);
}

void	init_path_loop(t_search *s, char **path, char **envp, t_data *data)
{
	char	*equal;
	int		len;

	while (path[s->path_count])
	{
		if (!ft_strncmp(path[s->path_count], s->list->content, \
				ft_strlen(path[s->path_count])))
		{
			equal = s->list->content;
			len = (int)ft_strlen(path[s->path_count]);
			if (((char *)s->list->content)[len] == '/')
				len++;
			if (!(s->list->content = ft_strdup(s->list->content + len)))
				error_standart(NULL);
			free(equal);
		}
		if (!(s->dir_folder = opendir((const char *)path[s->path_count])))
        {
            s->path_count++;
            continue ;
        }
		while ((s->dir = readdir(s->dir_folder)))
			if (init_dir_loop(s, envp, data, path))
				return ;
		s->path_count++;
	}
}

void	init_search(char **path, t_list *list, char **envp, t_data *data)
{
	t_search	s;
	t_parse		*tmp;

	s.path_count = 0;
	tmp = data->parse;
	s.list_count = ft_lstsize(tmp->param);
	tmp = tmp->next;
	while (data->nod)
	{
		s.list_count += ft_lstsize(tmp->param);
		if (parse_cmp("<>", tmp->delim))
			s.list_count--;
		tmp = tmp->next;
		data->nod--;
	}
	s.list = list;
	s.args = ft_calloc((size_t)s.list_count + 1, sizeof(char *));
	init_path_loop(&s, path, envp, data);
	error_command(list, "command not found", data);
	exit(127);
}

int		init_dirs(char **envp, t_list *list, t_data *data)
{
	t_dirs	d;

	init_dirs_struct(data, &d);
	while (envp[d.i])
	{
		if (!ft_strncmp(envp[d.i], PATH, 5))
		{
			d.flag = 1;
			if (((char *)data->parse->param->content)[0] == '.')
				init_relative_path(&d, envp, data);
			else
				d.buf2 = ft_strdup(&envp[d.i][5]);
			if (!(d.path = ft_split(d.buf2, ':')))
				error_standart(data);
			free(d.buf2);
			break ;
		}
		d.i++;
	}
	init_utils_if(envp, &d, data);
	if (d.flag == 0)
		init_utils_error(data, list);
	init_search(d.path, list, envp, data);
	ft_free_arr(&(d.path));
	return (1);
}
