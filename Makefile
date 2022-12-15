NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SOURCE := logic/*.c
GETNEXTLINE := get_next_line/*.c
LIBFT := libft/*.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
		make -C $(MINILIBX)
		$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBFT) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
				make clean -C $(MINILIBX)
				rm -rf $(NAME)

re: fclean all