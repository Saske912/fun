# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 18:23:32 by pfile             #+#    #+#              #
#    Updated: 2020/09/30 10:30:07 by pfile            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

HEADERS = libft.h

FIRST_PART = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o\
		 ft_memchr.o ft_memcmp.o ft_strlen.o ft_strlcpy.o ft_strlcat.o\
		 ft_strchr.o ft_strrchr.o ft_strnstr.o ft_strncmp.o ft_atoi.o\
		 ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
		 ft_toupper.o ft_tolower.o ft_calloc.o ft_strdup.o

SECOND_PART = ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o\
			  ft_strmapi.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o\
			  ft_putnbr_fd.o

ADDED_PART = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o\
			 ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o\
			 ft_lstmap.o ft_len_int.o mod.o\

BASIC_PART = ft_putchar.o ft_putnbr.o ft_putstr.o ft_strstr.o ft_strcmp.o\
			 ft_strrev.o ft_ultimate_div_mod.o ft_recursive_power.o\
			 ft_recursive_factorial.o ft_fibonacci.o ft_find_next_prime.o\
			 ft_sqrt.o ft_is_prime.o ft_strcpy.o ft_strlowcase.o\
			 ft_str_is_alpha.o ft_strupcase.o ft_strcapitalize.o\
			 ft_str_is_numeric.o ft_str_is_lowercase.o\
			 ft_str_is_uppercase.o ft_str_is_printable.o ft_strcat.o\
			 ft_concat_params.o ft_range.o ft_ultimate_range.o\
			 ft_strndup.o

BONUS_PART = $(ADDED_PART) $(BASIC_PART)

MAIN_PART = $(FIRST_PART) $(SECOND_PART)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MAIN_PART)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(MAIN_PART) $(BONUS_PART)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

bonus: $(BONUS_PART) $(MAIN_PART)
	ar rcs $(NAME) $^
