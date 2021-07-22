/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:57:54 by pfile             #+#    #+#             */
/*   Updated: 2020/10/18 22:21:23 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

/*
**bracket_loop
*/
void	bracket_loop(char **str, t_br *t, t_data *data);
/*
**redir_own
*/
void	redir_own_one(t_parse **tmp, t_data *data, int *k);
void	redir_own_two(t_parse **tmp, t_data *data, int *k);
void	redir_own_in_funcs(t_data *data);
/*
**pull
*/
void	pull_util(t_parse *tmp, t_data *data);
int		pull_pipe(t_data *data, char delim);
int		pull_end_out(t_data *data, char *delim, t_search *s, int *k);
void	pull_tainer(t_parse *tmp, t_data *data);
int		pull_in(t_data *data, char *delim, t_search *s, int *k);
int		pull_out(t_data *data, char *delim, t_search *s, int *k);
void	pull_tainer_check_loop(int *k, t_parse **tmp, t_data *data);
/*
**get
*/
void	get_standart(t_data *data, int sock, int ip, int port);
int		get_no_shell(char *str);
int		get_own(char *str);
int		get_env(char **str, t_counter *c, t_data *data);
/*
**init
*/
void	init_utils_if(char **envp, t_dirs *d, t_data *data);
void	init_utils_error(t_data *data, t_list *list);
void	init_relative_path(t_dirs *d, char **envp, t_data *data);
void	init_dirs_struct(t_data *data, t_dirs *d);
int		init_dirs(char **envp, t_list *list, t_data *data);
void	init_free(char ***path);
void	init_search(char **path, t_list *list, char **envp, t_data *data);
char	**init_env(char **old, char *str);
void	init_env2(t_data *data, char *str);
int		init_delim_check(t_data *data, t_search *s, int *k);
/*
**error
*/
void	error_standart(t_data *data);
void	error_command(t_list *list, char *str, t_data *data);
void	error_own(char *command, char *str, char *message, t_data *data);
void	error_base(t_data *data);
void	error_specials(char *str, char c, t_data *data);
/*
**parse_util
*/
int		parse_util_breaker(char *str, t_counter *c, t_data *data);
/*
**parse
*/
void	parse_low_case(t_data *data);
int		parse_argv(t_data *data);
void	parse_arg(t_data *data);
int		parse_cmp(char *comp, char c);
int		parse_ok(int i, int k);
void	parse_comand(char **str1, char *str2, t_counter *c, char *str3);
void	parse_init(t_counter *c, char *str);
/*
**ft
*/
t_parse	*ft_parsenew(void);
void	ft_free_arr(char ***arr);
void	ft_putstrn_fd(char *s, int n, int fd);
void	ft_free_data(t_data *data);
void	ft_check_dollar_question(t_parse **tmp, t_data *data);
/*
**func_branch
*/
int		ft_echo(t_list *param, t_data *data);
int		ft_pwd(t_data *data);
int		ft_cd(t_data *data);
int		ft_env(char **envp, t_data *data);
int		ft_export(t_data *data);
int		ft_unset(t_data *data);
int		ft_exit(t_data *data);
void	ft_exitcode(int status, t_data *data);
char	*ft_read_line(int fd2);
int		ft_read_check(t_data *data, char **line);
int		check_repeat_pro(char **arr, char *str);
/*
**func_branch_utils
*/
int		count_tab(char **tab);
int		sym_search(const char *str, char c);
int		check_repeat(char **arr, char *str);
void	handle_env_var(t_data *data, char *str);
int		ft_check_input(char *str);
/*
**check
*/
void	check_command(t_data *data);
void	check_bracket(char **str, int i, int k, t_data *data);
void	check_loop(t_counter *c, t_data *data, char **str, char **counter);
/*
**del
*/
void	del_bracket(char **str, int count, int c);
void	del_double_array(char ***arr);
/*
**fill
*/
void	fill_buffer(int i, int k, char **str, char d);
void	fill_val(t_counter *c, char **str, int k, char **buff);
void	fill_dollar(char **str3, t_data *data);
/*
**signals
*/
void	ft_sigint(void);
void	ft_sigquit(void);
void	ft_sigquit_spec(char **line);
/*
**redirect
*/
void	redirect_from_file(t_data *data, char *str);

void error_exit(const char * err);
void check_int_fatal(int ret, char *msg);

#endif
