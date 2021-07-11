/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:45:30 by pfile             #+#    #+#             */
/*   Updated: 2020/10/04 15:27:48 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 64

int		get_next_line(int fd, char **line);
char	*get_join(char *str, int len, char ***sneak, int **eol);
char	*compare_readed(int	*stat, char **sneak, char ***line);
char	*s_strdup(char *str);

#endif
