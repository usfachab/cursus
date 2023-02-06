NAME=so_long
CFLAGS += -Wall -Wextra -Werror
CC=cc
SRC=get_map_line.c utils/split.c utils/flood.c utils/helper.c utils/structInit.c utils/stderr.c utils/check.c \
	utils/startPos.c utils/readMap.c utils/checkHelp.c main.c utils/direction.c

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re : fclean $(NAME)