# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 17:48:55 by yachaab           #+#    #+#              #
#    Updated: 2023/02/04 11:44:47 by yachaab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_M = ./mandatory/pipex

NAME_B = ./bonus/pipex_bonus

CFLAGS += -Wall -Wextra -Werror

CC = cc

SRC_M =	./mandatory/main.c ./mandatory/utils/pipex.c ./mandatory/utils/stderr.c ./mandatory/utils/parsing.c ./mandatory/utils/helpers.c \
		./mandatory/utils/ft_split.c ./mandatory/utils/initargs.c ./mandatory/utils/dry.c

SRC_B =	./bonus/main.c ./bonus/utils/ft_pipex_bonus.c ./bonus/utils/ft_stderr_bonus.c \
		./bonus/utils/ft_parse_bonus.c ./bonus/utils/ft_help_bonus.c ./bonus/utils/ft_exec_bonus.c \
		./bonus/utils/ft_split_bonus.c ./bonus/utils/ft_init_struct_bonus.c \
		./bonus/utils/ft_init_var_bonus.c ./bonus/utils/ft_dup_bonus.c ./bonus/function/get_next_line_bonus.c \
		./bonus/utils/ft_heredoc_bonus.c ./bonus/function/get_next_line_utils_bonus.c

OBJ_M = $(SRC_M:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all : $(NAME_M)

$(NAME_M) : $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) -o $@

bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $@

clean:
	@rm -fr $(OBJ_M) $(OBJ_B)
	@echo "clean objs done."
	
fclean: clean
	@rm -fr $(NAME_M) $(NAME_B)
	@echo "clean all done."

re : fclean $(NAME_M) $(NAME_B)
	