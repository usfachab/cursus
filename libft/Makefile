# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 21:12:05 by yachaab           #+#    #+#              #
#    Updated: 2022/11/01 10:14:30 by yachaab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_M =	ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
		ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_bzero.c \
		ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memchr.c ft_putstr_fd.c \
		ft_strlen.c ft_toupper.c ft_isalnum.c ft_memcmp.c ft_split.c ft_strmapi.c \
		ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isascii.c ft_memmove.c ft_strdup.c \
		ft_strnstr.c ft_isdigit.c ft_memset.c ft_striteri.c ft_strrchr.c

SRC_B = ft_lstadd_back_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstclear_bonus.c ft_lstlast_bonus.c
		
OBJ_M = $(SRC_M:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror

AR = ar rsc

all : $(NAME)

$(NAME) : $(OBJ_M)
	@$(AR) $(NAME) $^
	
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(AR) $(NAME) $@
	
bonus : $(OBJ_B) $(OBJ_M) $(NAME)
	
	
clean :
	@rm -fr $(OBJ_M) $(OBJ_B)

fclean : clean
	@rm -fr $(NAME)

re : fclean all