# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 17:48:55 by yachaab           #+#    #+#              #
#    Updated: 2023/02/04 21:30:15 by yachaab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_M = push_swap

CFLAGS += -Wall -Wextra -Werror

CC = cc

SRC_M =	main.c func/ft_atoi.c func/ft_isdigit.c func/ft_strlen.c utils/qb_stderr.c \
		utils/qb_is_dup.c

OBJ_M = $(SRC_M:.c=.o)


all : $(NAME_M)

$(NAME_M) : $(OBJ_M)
	$(CC) $(CFLAGS) $(OBJ_M) -o $@

clean:
	@rm -fr $(OBJ_M)
	@echo "clean OBJ done."
	
fclean: clean
	@rm -fr $(NAME_M)
	@echo "clean all done."

re : fclean $(NAME_M)
	