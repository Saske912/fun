/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:18:49 by pfile             #+#    #+#             */
/*   Updated: 2020/10/02 12:37:39 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse		*ft_parsenew(void)
{
	t_parse	*tmp;

	if (!(tmp = (t_parse *)ft_calloc(1, sizeof(t_parse))))
		error_standart(NULL);
	tmp->str = NULL;
	tmp->delim = 0;
	tmp->param = NULL;
	tmp->next = NULL;
	return (tmp);
}

void		ft_free_arr(char ***arr)
{
	int		i;

	i = -1;
	while ((*arr)[++i])
		free((*arr)[i]);
	free(*arr);
}

void		ft_putstrn_fd(char *s, int n, int fd)
{
	int		i;

	i = -1;
	if (s)
		while (++i < n)
			ft_putchar_fd(s[i], fd);
}

void		ft_free_data(t_data *data)
{
	t_parse	*tmp;

	if (data->str)
		free(data->str);
	tmp = data->head;
	while (data->head)
	{
		if (data->head->str && *data->head->str != '\0')
			free(data->head->str);
		if (data->head->head)
			ft_lstclear(&data->head->head, free);
		tmp = tmp->next;
		if (data->head)
			free(data->head);
		data->head = tmp;
	}
}

void		ft_check_dollar_question(t_parse **tmp, t_data *data)
{
	t_list	*tmp2;
	char	*buf;

	if (!(buf = ft_strdup("$?")))
		error_standart(NULL);
	tmp2 = (*tmp)->param;
	while (tmp2)
	{
		if (!strcmp((char *)tmp2->content, buf))
		{
			free(tmp2->content);
			if (!(tmp2->content = ft_itoa(data->error_code)))
				error_standart(NULL);
		}
		tmp2 = tmp2->next;
	}
	free(buf);
}
