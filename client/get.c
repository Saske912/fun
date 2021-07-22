/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:56:46 by pfile             #+#    #+#             */
/*   Updated: 2020/10/25 16:35:42 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_value(char **str, t_data *data)
{
	char	**env;
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(*str);
	env = data->envp;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], *str, len) && env[i][(int)len] == '=')
		{
			free(*str);
			if (!(*str = ft_strdup(&env[i][len + 1])))
				error_standart(NULL);
			return (1);
		}
	}
	if (!strcmp("?", *str))
	{
		free(*str);
		if (!(*str = ft_strdup("$?")))
			error_standart(NULL);
		return (1);
	}
	return (0);
}

int		get_env(char **str, t_counter *c, t_data *data)
{
	char	*str3;
	int		k;

	k = 0;
	c->len++;
	if ((*str)[c->len] == '\0' || (*str)[c->len] == ' ')
	{
		if (!(str3 = ft_strdup("$")))
			error_standart(NULL);
		fill_val(c, str, k, &str3);
		return (0);
	}
	while ((*str)[c->len + k] && !parse_cmp(" \"\'$", (*str)[c->len + k]))
		k++;
	if (!(str3 = ft_substr(*str, c->len, k)))
		error_standart(NULL);
	if (!get_value(&str3, data))
	{
		fill_dollar(&str3, data);
		fill_val(c, str, k, &str3);
		return (0);
	}
	fill_val(c, str, k, &str3);
	return (1);
}

int		get_no_shell(char *str)
{
	if (!str)
		return (-1);
	return (ft_strncmp(ECHO, str, 4) && ft_strncmp(PWD, str, 3) &&
			ft_strncmp(EXP, str, 6) && ft_strncmp(UNS, str, 4) &&
			ft_strncmp(ENV, str, 3) && ft_strncmp(EXI, str, 4) &&
			ft_strncmp(CD, str, 2));
}

int		get_own(char *str)
{
	return (ft_strcmp(ECHO, str) && ft_strcmp(PWD, str) &&
			ft_strcmp(EXP, str) && ft_strcmp(UNS, str) &&
			ft_strcmp(ENV, str) && ft_strcmp(EXI, str) &&
			ft_strcmp(CD, str));
}

void	get_standart(t_data *data, int sock, int ip, int port)
{
//	char	*line;
	struct sockaddr_in addr;
	socklen_t len;
	data->k[0] = 0;
	data->k[1] = 1;
	dup2(sock, 1);
	dup2(sock, 2);
	data->fd_dst = dup(1);
	data->fd_src = dup(0);
	fd_set read_fd;
    char *line;
    char buf[400];
    if (!line)
        error_exit("malloc error");
    int ret;
    struct timeval tv;

    tv.tv_sec = 3;
    tv.tv_usec = 0;
	while (1)
	{
		g_sigquit = 0;
		g_sigint = 0;
//		line = ft_read_line(data->fd_src);
        FD_ZERO(&read_fd);
        FD_SET(sock, &read_fd);
        ret = select(sock + 1, &read_fd, NULL, NULL, &tv);
        check_int_fatal(ret, "select");
		socklen_t check_len = sizeof(ret);
		getsockopt(sock, SOL_SOCKET, SO_ERROR, &ret, &check_len);
//		write(2, "here\n", 5);
		if (ret == 54)
		{
			write(2, "here\n", 5);
			do {
				close(sock);
				sock = socket(AF_INET, SOCK_STREAM, 0);
				int val = 1;
				setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
				check_int_fatal(sock, "socket");
				ft_bzero(&addr, sizeof(addr));
				addr.sin_addr.s_addr = ip;
				addr.sin_port = port;
				len = sizeof(addr);
				ret = connect(sock, (const struct sockaddr *)&addr, len);
				if (ret == -1)
				{
					close(sock);
					sleep(3);
				}
			}
			while (ret == -1);
			dup2(sock, 1);
			dup2(sock, 2);
			continue ;
		}
        if (!ret)
            continue ;
        if ( FD_ISSET(sock, &read_fd))
        {
//            write(2, SHELL, 10);
            bzero(buf, 400);
            ret = recv(sock, buf, 399, 0);
            check_int_fatal(ret, "recv");
            line = strdup(buf);
            if (!line)
                error_exit("malloc error");
//            write(2, line, ft_strlen(line));
            if (ft_read_check(data, &line))
                continue ;
            if (!(data->str = ft_strtrim(line, " ")))
                error_standart(NULL);
            free(line);
            if (parse_cmp(";|", *data->str))
                error_specials(NULL, *data->str, data);
            else if (parse_cmp("><", *data->str))
                error_specials("newline", 0, data);
            else
                parse_arg(data);
            ft_free_data(data);
//			do {
//				close(sock);
//				sock = socket(AF_INET, SOCK_STREAM, 0);
//				int val = 1;
//				setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
//				check_int_fatal(sock, "socket");
//				ft_bzero(&addr, sizeof(addr));
////		addr.sin_addr.s_addr = inet_addr(av[1]);
////		addr.sin_port = htons(atoi(av[2]));
//				addr.sin_addr.s_addr = ip;
//				addr.sin_port = port;
//				len = sizeof(addr);
//				ret = connect(sock, (const struct sockaddr *)&addr, len);
//				if (ret == -1)
//				{
//					write(2, "ret == -1", ft_strlen("ret == -1"));
//					close(sock);
//					sleep(3);
//				}
//			}
//			while (ret == -1);
//			write(2, "connected", ft_strlen("connected"));
        }
	}
}
