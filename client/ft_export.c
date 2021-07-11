/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:07:56 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/18 22:27:28 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_print(char **sorted, t_data *data)
{
	int		i;
	int		len;

	i = 0;
	while (sorted[i])
	{
		ft_putstr_fd("declare -x ", data->k[1]);
		len = sym_search(sorted[i], '=');
		if (len == -1)
			ft_putstr_fd(sorted[i], data->k[1]);
		else
		{
			len++;
			ft_putstrn_fd(sorted[i], len, data->k[1]);
			ft_putstr_fd("\"", data->k[1]);
			ft_putstr_fd(sorted[i] + len, data->k[1]);
			ft_putstr_fd("\"", data->k[1]);
		}
		write(data->k[1], "\n", 1);
		i++;
	}
}

void	add_env(t_data *data, char *str)
{
	char	**line;
	int		i;

	i = 0;
	while (data->envp[i])
		i++;
	if (str)
		i++;
	if (!(line = (char **)ft_calloc(i + 1, sizeof(char *))))
		error_standart(NULL);
	i = 0;
	while (data->envp[i])
	{
		if (!(line[i] = ft_strdup(data->envp[i])))
			error_standart(NULL);
		i++;
	}
	if (str)
		if (!(line[i++] = ft_strdup(str)))
			error_standart(NULL);
	line[i] = NULL;
	ft_free_arr(&data->envp);
	data->envp = line;
}

void	ft_export_sort(t_data *data, int len)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (data->envp[i])
	{
		j = ++i;
		while (j < len)
		{
			if (ft_strncmp(data->envp[i], data->envp[j], \
			ft_strlen(data->envp[i])) > 0)
			{
				if (!(tmp = ft_strdup(data->envp[j])))
					error_standart(NULL);
				free(data->envp[j]);
				if (!(data->envp[j] = ft_strdup(data->envp[i])))
					error_standart(NULL);
				free(data->envp[i]);
				data->envp[i] = tmp;
			}
			j++;
		}
	}
	ft_export_print(data->envp, data);
}

void	ft_handle_export_line(t_data *data, t_list *tmp)
{
	int		repeat;
	char	*new_str;

	if (!(strcmp(tmp->content, "_")))
		return ;
	if (!(new_str = ft_strdup(tmp->content)))
		error_standart(NULL);
	if ((repeat = check_repeat_pro(data->envp, new_str)) == -1)
		add_env(data, new_str);
	else if (repeat == -2)
	{
		free(new_str);
		return ;
	}
	else
	{
		free(data->envp[repeat]);
		data->envp[repeat] = ft_strdup(new_str);
	}
	handle_env_var(data, new_str);
	free(new_str);
}

int		ft_export(t_data *data)
{
	t_list	*tmp;

	tmp = data->parse->param->next;
	if (!tmp)
		ft_export_sort(data, count_tab(data->envp));
	while (tmp)
	{
		if (((char *)tmp->content)[0] == '\0')
		{
			tmp = tmp->next;
			continue ;
		}
		else if ((!ft_isalpha(((char *)tmp->content)[0])
				&& ((char *)tmp->content)[0] != '_')
				|| ft_check_input((char *)tmp->content))
			error_own("export", tmp->content, "not a valid identifier", data);
		else
			ft_handle_export_line(data, tmp);
		tmp = tmp->next;
	}
	return (!data->error_code ? 0 : 1);
}
