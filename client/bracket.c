/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:58:22 by pfile             #+#    #+#             */
/*   Updated: 2020/10/29 15:58:26 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bracket_loop(char **str, t_br *t, t_data *data)
{
	while (t->n < t->len)
	{
		if (parse_cmp("\'\"", (*str)[t->n + t->b]))
		{
			t->br = (*str)[t->n + t->b];
			if ((*str)[t->n + t->b] == '\'')
				data->parse->one_q++;
			else
				data->parse->two_q++;
			t->b++;
			while (t->n + t->b < t->len + t->i + t->k \
				&& t->br != (*str)[t->n + t->b])
			{
				t->new_str[t->n] = (*str)[t->n + t->b];
				t->n++;
			}
			if (t->n < t->len && (*str)[t->n + t->b] == t->br)
			{
				t->b++;
				continue ;
			}
		}
		t->new_str[t->n] = (*str)[t->n + t->b];
		t->n++;
	}
}
