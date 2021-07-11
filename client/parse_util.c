/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:19:45 by pfile             #+#    #+#             */
/*   Updated: 2020/10/25 13:49:44 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parse_util_breaker(char *str, t_counter *c, t_data *data)
{
	if (c->len + 1 < (int)ft_strlen(str) && str[c->len] == '>'\
			&& str[c->len + 1] == '>')
	{
		parse_comand(&data->parse->str, str, c, " >");
		data->parse->delim = '#';
		c->len++;
		return (1);
	}
	else if (parse_cmp("|;<>", str[c->len]) && parse_ok(c->i, c->k))
	{
		parse_comand(&data->parse->str, str, c, " ");
		data->parse->delim = str[c->len];
		return (1);
	}
	else if (!str[c->len])
	{
		parse_comand(&data->parse->str, str, c, " \n");
		c->end = 1;
		return (1);
	}
	return (0);
}

int		parse_ok(int i, int k)
{
	return (!(i % 2) && !(k % 2));
}

int		parse_cmp(char *comp, char c)
{
	while (*comp)
		if (*comp++ == c)
			return (1);
	return (0);
}

void	parse_comand(char **str1, char *str2, t_counter *c, char *str3)
{
	char	*strcopy;

	if (!(strcopy = ft_substr(str2, c->start, c->len - c->start)))
		error_standart(NULL);
	if (!(*str1 = ft_strtrim(strcopy, str3)))
		error_standart(NULL);
	free(strcopy);
}

void	parse_init(t_counter *c, char *str)
{
	c->i = 0;
	c->k = 0;
	c->len = 0;
	c->end = 0;
	c->strlen = ft_strlen(str);
}
