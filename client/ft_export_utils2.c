/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:07:56 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/18 22:27:28 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_tab(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

int		sym_search(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_input(char *str)
{
	int		i;

	i = 0;
	while (i < ft_strlen(str) && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	handle_env_var(t_data *data, char *str)
{
	int		repeat;
	char	**new_env;

	if ((repeat = check_repeat(data->env_var, str)) == -1)
	{
		if (sym_search(str, '=') != -1)
		{
			if (!(new_env = init_env(data->env_var, str)))
				error_standart(NULL);
			ft_free_arr(&data->env_var);
			data->env_var = new_env;
		}
	}
	else
	{
		if (sym_search(str, '=') == -1)
			return ;
		else
		{
			free(data->env_var[repeat]);
			data->env_var[repeat] = ft_strdup(str);
		}
	}
}
