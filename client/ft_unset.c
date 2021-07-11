/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:29:05 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/18 22:08:36 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_env(char **env, t_list *tmp)
{
	int		i;
	int		k;

	i = 0;
	while (env[i])
	{
		if (!strncmp(tmp->content, env[i], ft_strlen(tmp->content)))
		{
			free(env[i]);
			env[i] = NULL;
			k = i + 1;
			while (env[k])
			{
				env[i] = env[k];
				i++;
				k++;
			}
			env[i] = NULL;
		}
		i++;
	}
}

int		check_unname(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*buf;
	char	**tmp;

	i = 0;
	tmp = data->env_var;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j] != '=')
			j++;
		if (!(buf = ft_strndup(tmp[i], j)))
			error_standart(NULL);
		if ((ft_strcmp(str, buf)) == 0)
		{
			free(buf);
			return (1);
		}
		free(buf);
		i++;
	}
	return (0);
}

void	check_tmp_content(char *str, t_data *data)
{
	if (str[0] == '$')
		error_own("unset", str, "not a valid identifier", data);
	else if (!ft_isalpha(str[0]) && str[0] != '_')
		error_own("unset", str, "not a valid identifier", data);
}

int		ft_unset(t_data *data)
{
	t_list	*tmp;

	tmp = data->parse->param->next;
	while (tmp)
	{
		if (((char *)tmp->content)[0] == '\0')
		{
			tmp = tmp->next;
			continue ;
		}
		if (!strcmp("$", tmp->content))
			error_own("unset", tmp->content, "not a valid identifier", data);
		else if (check_unname((char *)tmp->content, data) == 0)
			check_tmp_content(tmp->content, data);
		else
		{
			handle_env(data->envp, tmp);
			handle_env(data->env_var, tmp);
		}
		tmp = tmp->next;
	}
	return (!data->error_code ? 0 : 1);
}
