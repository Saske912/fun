/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:49:08 by pfile             #+#    #+#             */
/*   Updated: 2020/10/18 21:47:03 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_base(t_data *data)
{
	t_list		*tmp;

	tmp = data->parse->param;
	write(1, "minishell: ", 11);
	while (tmp)
	{
		ft_putstr(tmp->content);
		write(1, ": ", 2);
		tmp = tmp->next;
	}
}

void	error_standart(t_data *data)
{
	error_base(data);
	ft_putstr(strerror(errno));
	ft_putchar('\n');
	data->error_code = 1;
}

void	error_own(char *command, char *str, char *message, t_data *data)
{
	write(1, "minishell: ", 11);
	ft_putstr(command);
	write(1, ": ", 2);
	write(1, "`", 1);
	ft_putstr(str);
	write(1, "'", 1);
	write(1, ": ", 2);
	ft_putstr(message);
	ft_putchar('\n');
	data->error_code = 1;
}

void	error_command(t_list *list, char *str, t_data *data)
{
	write(1, "minishell: ", 11);
	ft_putstr(list->content);
	write(1, ": ", 2);
	ft_putstr(str);
	ft_putchar('\n');
	data->error_code = 127;
}

void	error_specials(char *str, char c, t_data *data)
{
	ft_putstr("minishell: syntax error near unexpected token `");
	if (!str)
		ft_putchar(c);
	else
		ft_putstr(str);
	ft_putchar('\'');
	ft_putchar('\n');
	data->error_code = 258;
}
