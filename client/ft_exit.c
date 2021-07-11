/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:33:02 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/18 22:21:13 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exitcode(int status, t_data *data)
{
	int		signal;

	if (WIFSIGNALED(status))
	{
		if ((signal = WTERMSIG(status)) == SIGQUIT)
		{
			ft_putstr_fd("Quit: ", 1);
			ft_putnbr(signal);
			ft_putstr_fd("\n", 1);
		}
		data->error_code = 128 + signal;
		return ;
	}
	data->error_code = WEXITSTATUS(status);
}

int		ft_exit(t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = data->parse->param->next;
	if (data->parse->delim == '|')
		return (1);
	if (!tmp)
		exit(0);
	while (((char *)tmp->content)[i])
	{
		if (ft_isdigit(((char *)tmp->content)[i]))
			i++;
		else
		{
			error_own("exit", tmp->content, "numeric argument required", data);
			exit(255);
		}
	}
	if (tmp->next)
		error_own("exit", tmp->content, "too many arguments", data);
	else
		exit(ft_atoi(tmp->content));
	return (1);
}


void error_exit(const char * err)
{
//    close(sock);
    perror(err);
    exit(1);
}

void check_int_fatal(int ret, char *msg)
{
    if (ret == -1)
    {
        error_exit(msg);
    }
}
