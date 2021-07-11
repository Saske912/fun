/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:07:56 by ttarsha           #+#    #+#             */
/*   Updated: 2020/10/18 16:51:27 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(void)
{
	if (g_read_started)
		ft_putstr_fd("\b\b  \b\b\nminishell:", 1);
	else
		ft_putstr_fd("\n", 1);
	g_sigint = 1;
}

void	ft_sigquit(void)
{
	g_sigquit = 1;
	if (g_read_started)
		ft_putstr_fd("\b\b  \b\b", 1);
}
