/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:07:56 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/18 22:27:28 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_repeat_if_else(t_check *t, char **arr, char *str)
{
	if (!(t->buf2 = ft_strndup(str, t->sym2)))
		error_standart(NULL);
	if (!strcmp(arr[t->i], t->buf2))
	{
		free(t->buf2);
		return (t->i);
	}
	free(t->buf2);
	return (-4);
}

int		check_repeat_if(t_check *t, char **arr, char *str)
{
	t->sym = sym_search(arr[t->i], '=');
	if (t->sym != -1)
	{
		if (!(t->buf = ft_strndup(arr[t->i], t->sym)))
			error_standart(NULL);
		if (!(t->buf2 = ft_strndup(str, t->sym2)))
			error_standart(NULL);
		if (!strcmp(t->buf, t->buf2))
		{
			free(t->buf);
			free(t->buf2);
			return (t->i);
		}
		free(t->buf);
		free(t->buf2);
	}
	else if (!strncmp(arr[t->i], str, t->sym2))
		if (check_repeat_if_else(t, arr, str) != -4)
			return (t->i);
	return (-3);
}

int		check_repeat_else(t_check *t, char **arr, char *str)
{
	t->sym = sym_search(arr[t->i], '=');
	if (t->sym != -1)
	{
		if (!(t->buf = ft_strndup(arr[t->i], t->sym)))
			error_standart(NULL);
		if (!strcmp(t->buf, str))
		{
			free(t->buf);
			return (-2);
		}
		free(t->buf);
	}
	return (-3);
}

int		check_repeat_pro(char **arr, char *str)
{
	t_check t;
	int		k;

	t.i = 0;
	while (arr[t.i])
	{
		if (!strcmp(arr[t.i], str))
			return (-2);
		t.sym2 = sym_search(str, '=');
		if (t.sym2 != -1)
			k = check_repeat_if(&t, arr, str);
		else
			k = check_repeat_else(&t, arr, str);
		if (k == -3)
			t.i++;
		else
			return (k);
	}
	return (-1);
}

int		check_repeat(char **arr, char *str)
{
	int		i;
	int		sym;

	i = 0;
	while (arr[i])
	{
		sym = sym_search(arr[i], '=');
		if (sym == -1)
		{
			if (ft_strncmp(str, arr[i], ft_strlen(arr[i])) == 0)
				return (i);
			i++;
		}
		else
		{
			if (ft_strncmp(str, arr[i], sym) == 0)
				return (i);
			i++;
		}
	}
	return (-1);
}
