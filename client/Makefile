# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 13:35:00 by pfile             #+#    #+#              #
#    Updated: 2020/10/25 13:41:47 by ttarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=tool

OBJS_DIR=bins/
SRC=	main.c \
		get_next_line.c \
		get_next_line_utils.c \
		init.c \
		get.c \
		error.c \
		parse.c \
		ft.c \
		ft_echo.c \
		ft_pwd.c \
		ft_cd.c \
		check.c \
		ft_env.c \
		ft_export.c \
		fill.c \
		ft_unset.c \
		ft_exit.c \
		pull.c \
		parse_util.c \
		ft_signals.c \
		pull_utils.c \
		ft_export_utils.c \
		ft_read.c \
		redir_own.c \
		bracket.c \
        init_utils.c \
        ft_export_utils2.c

OBJ=$(addprefix $(OBJS_DIR),$(SRC:.c=.o))

CC=gcc

LIB_DIR=libft/
LFT=libft.a
FLAGS=-Wall -Wextra -Werror

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):	
	mkdir -p	$(OBJS_DIR)

$(NAME): $(OBJ)
	make bonus -C $(LIB_DIR)
	mv $(LIB_DIR)$(LFT) .
	$(CC) -g $(OBJ) -L. $(LFT) -o $(NAME)

$(OBJ):	$(OBJS_DIR)%.o: %.c
	$(CC) -g $(GCC_FLAGS) -c $< -o $@

clean:
	rm -f  libft/*.o
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(LFT)

re: fclean all

bonus: all

.PHONY: all clean bonus fclean re
