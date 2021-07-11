/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:07:56 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/18 22:14:45 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_change_env_next(char **arr, int i, int k, char **buf)
{
	char	*tmp;

	free(arr[k]);
	free(arr[i]);
	if (!(tmp = getcwd(NULL, 0)))
		error_standart(NULL);
	if (!(arr[k] = ft_strjoin("OLDPWD=", *buf)))
		error_standart(NULL);
	if (!(arr[i] = ft_strjoin("PWD=", tmp)))
		error_standart(NULL);
	free(tmp);
	free(*buf);
}

void	change_env(char **arr)
{
	int		i;
	int		k;
	char	*buf;
	size_t	size;

	i = 0;
	k = 0;
	while (strncmp(arr[k], "OLDPWD=", 7) != 0)
		k++;
	while (strncmp(arr[i], "PWD=", 4) != 0)
		i++;
	size = ft_strlen(&arr[i][4]);
	if (!(buf = malloc(sizeof(char) * size + 1)))
		error_standart(NULL);
	if (!ft_strcpy(buf, &arr[i][4]))
		error_standart(NULL);
	ft_change_env_next(arr, i, k, &buf);
}

char	*go_home(t_data *data)
{
	char	*buf;
	size_t	size;
	int		i;

	i = 0;
	while (data->envp[i] && strncmp(data->envp[i], "HOME=", 5) != 0)
		i++;
	if (!data->envp[i])
	{
		ft_putstr("minishell: cd: HOME not set\n");
		return (NULL);
	}
	size = ft_strlen(&data->envp[i][5]);
	if (!(buf = malloc(sizeof(char) * size + 1)))
		error_standart(NULL);
	if (!(ft_strcpy(buf, &data->envp[i][5])))
		error_standart(NULL);
	return (buf);
}

int		ft_cd(t_data *data)
{
	char	*buf;
	int		res;
	t_list	*tmp;

	tmp = data->parse->param->next;
	if (!tmp)
		buf = go_home(data);
	else
	{
		if (!(buf = ft_strdup(tmp->content)))
			error_standart(NULL);
	}
	if (buf)
		res = chdir(buf);
	else
		return (1);
	if (res == 0)
	{
		change_env(data->envp);
		change_env(data->env_var);
	}
	else
		error_own("cd", buf, strerror(errno), data);
	free(buf);
	return (!data->error_code ? 0 : 1);
}
