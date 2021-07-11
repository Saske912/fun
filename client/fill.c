/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:14:58 by pfile             #+#    #+#             */
/*   Updated: 2020/10/25 16:46:06 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_dollar_with_equal_for_own_funcs(int sym, char **str3)
{
	char	*str4;
	char	*buf;

	if (sym == 0)
	{
		str4 = *str3;
		if (!(*str3 = ft_strjoin("$", *str3)))
			error_standart(NULL);
		free(str4);
	}
	else
	{
		if (!(buf = ft_strdup(*str3 + sym)))
			error_standart(NULL);
		free(*str3);
		*str3 = buf;
	}
}

void	fill_dollar(char **str3, t_data *data)
{
	int		sym;

	if (data->parse->param && get_own(data->parse->head->content))
	{
		free(*str3);
		if (!(*str3 = ft_strdup("")))
			error_standart(NULL);
	}
	else
	{
		if ((sym = sym_search(*str3, '=')) >= 0)
			fill_dollar_with_equal_for_own_funcs(sym, str3);
		else
		{
			free(*str3);
			if (!(*str3 = ft_strdup("")))
				error_standart(NULL);
		}
	}
}

int		check_line_end(char **buff, char **str, char **str1, char **str2)
{
	if (*buff == '\0')
	{
		if (!(*str = ft_strjoin(*str1, *str2)))
			error_standart(NULL);
		free(*str1);
		free(*str2);
		return (1);
	}
	return (0);
}

void	fill_val(t_counter *c, char **str, int k, char **buff)
{
	char	*str1;
	char	*str2;
	char	*str4;
	size_t	i;

	i = ft_strlen(*buff);
	if (!*str)
		return ;
	if (!(str1 = ft_strndup(*str, c->len - 1)))
		error_standart(NULL);
	if (!(str2 = ft_strdup(&(*str)[c->len + k])))
		error_standart(NULL);
	if (check_line_end(buff, str, &str1, &str2))
		return ;
	free(*str);
	if (!(str4 = ft_strjoin(str1, *buff)))
		error_standart(NULL);
	free(str1);
	free(*buff);
	if (!(*str = ft_strjoin(str4, str2)))
		error_standart(NULL);
	free(str4);
	free(str2);
	c->len += i;
	c->strlen = ft_strlen(*str);
}
