/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:55:11 by pfile             #+#    #+#             */
/*   Updated: 2020/10/18 21:34:51 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SHELL "minishell: "
# define PATH "PATH="
# define ECHO "echo"
# define PWD "pwd"
# define EXP "export"
# define UNS "unset"
# define ENV "env"
# define EXI "exit"
# define CD "cd"
# define RDWR O_RDWR | O_CREAT | O_TRUNC, S_IRWXU
# define RDWRE O_RDWR | O_APPEND | O_CREAT, S_IRWXU
# define RD O_RDONLY

extern int		g_read_started;
extern int		g_sigquit;
extern int		g_sigint;

#endif
