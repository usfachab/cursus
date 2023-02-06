NAME = so_long

CFLAGS += -Wall -Wextra -Werror

CC = cc

SRC =	main.c exeCheck.c utils/checkmap.c utils/stderr.c utils/helper.c utils/readMap.c \
		utils/initstruc.c utils/split.c utils/initHelper.c utils/ft_flood.c utils/checkMapafter.c \
		utils/ft_render.c utils/ft_keyhook.c utils/ft_direction.c utils/ft_putnbr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re : fclean $(NAME)