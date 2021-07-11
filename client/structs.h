/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:52:37 by pfile             #+#    #+#             */
/*   Updated: 2020/10/15 17:32:09 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_check
{
	int		i;
	int		sym;
	int		sym2;
	char	*buf;
	char	*buf2;
}					t_check;

typedef struct		s_dirs
{
	int		i;
	char	**path;
	int		flag;
	char	*buf;
	int		len;
	int		slsh;
	char	*equal;
	char	*dirs;
	char	*buf2;
	int		p;
}					t_dirs;

typedef	struct		s_br
{
	int				n;
	int				b;
	int				len;
	char			*new_str;
	char			br;
	int				i;
	int				k;
}					t_br;

typedef struct		s_counter
{
	int				i;
	int				k;
	int				n;
	unsigned int	start;
	size_t			len;
	int				strlen;
	int				end;
}					t_counter;

typedef	struct		s_argv
{
	t_counter		c;
	char			*str;
	char			*counter;
	t_list			*list;
	t_list			*head;
	int				flag;
}					t_argv;

typedef	struct		s_search
{
	int				path_count;
	DIR				*dir_folder;
	struct dirent	*dir;
	char			*exec;
	char			*exec_path;
	char			**args;
	int				lst;
	int				list_count;
	t_list			*list;
}					t_search;

typedef struct		s_parse
{
	char			*str;
	char			delim;
	t_list			*param;
	t_list			*head;
	struct s_parse	*next;
	int				one_q;
	int				two_q;
	int				lstlen;
}					t_parse;

typedef struct		s_data
{
	int				rd_count;
	int				k[2];
	int				n[2];
	int				nod;
	char			**envp;
	char			*str;
	char			**env_var;
	int				fd_dst;
	int				fd_src;
	int				error_code;
	t_parse			*parse;
	t_parse			*head;
	t_counter		counter;
}					t_data;

#endif
