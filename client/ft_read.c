/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:29:05 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/18 22:08:36 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_read_loop(char **line, int fd2, char **buf, int *res)
{
	char	*tmp;

	g_read_started = 1;
	if ((*res = get_next_line(fd2, line)) == -1)
		error_standart(NULL);
	if (!(*res) && !ft_strlen(*line))
	{
		if (*line)
			free(*line);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (g_sigquit)
		g_sigquit = 0;
	if (!(*res))
	{
		ft_putstr_fd("  \b\b", 1);
		tmp = *buf;
		if (!(*buf = ft_strjoin(*buf, *line)))
			error_standart(NULL);
		free(tmp);
		free(*line);
	}
}

char	*ft_read_line(int fd2)
{
	char	*line;
	char	*buf;
	int		res;
	char	*tmp;

	line = NULL;
	if (!(buf = ft_strdup("")))
		error_standart(NULL);
	while (1)
	{
		ft_read_loop(&line, fd2, &buf, &res);
		if (res > 0)
			break ;
	}
	if (*buf != '\0')
	{
		tmp = buf;
		if (!(buf = ft_strjoin(buf, line)))
			error_standart(NULL);
		free(line);
		free(tmp);
		return (buf);
	}
	free(buf);
	return (line);
}

int		ft_read_check(t_data *data, char **line)
{
	if (g_sigint)
		data->error_code = 1;
	if (*(*line) == '\0')
	{
		free(*line);
		return (1);
	}
	return (0);
}
