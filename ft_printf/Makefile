# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 11:18:46 by yachaab           #+#    #+#              #
#    Updated: 2022/11/07 17:23:52 by yachaab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


SRC = ft_printf.c utils/ft_putchar.c utils/ft_putstr.c utils/ft_putnbr.c \
	utils/ft_putunbr.c utils/ft_puthex.c utils/ft_putptr.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS += -g3

AR = ar rc 

RM = rm -fr

all : $(NAME)

$(NAME) : $(OBJ)

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@$(AR) $(NAME) $@

clean : 
	@$(RM) $(OBJ)

fclean : clean 
	@$(RM) $(NAME) a.out

re : fclean all