/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 12:55:00 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/15 13:57:22 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_pwd(t_data *data)
{
	char	*buf;

	errno = 0;
	if (!(buf = getcwd(NULL, 0)))
		error_standart(data);
	write(data->k[1], buf, ft_strlen(buf));
	write(data->k[1], "\n", 1);
	free(buf);
	return (0);
}
