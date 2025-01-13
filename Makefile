SRCS 	= src/main.c src/utils.c

NAME	= so_long

CC 	= gcc
FLAGS	= -Wall -Werror -Wextra -g -Iincludes
MLX_FLAGS	= -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all:	$(NAME)
$(NAME):
		@cd printf && make
		@cd get_next_line && make
		$(CC) $(SRCS) $(FLAGS) $(MLX_FLAGS) printf/libftprintf.a get_next_line/get_next_line.a -o $(NAME)

		
clean:
		@cd printf && make clean
		@cd get_next_line && make clean

fclean:
		@cd printf && make fclean
		@cd get_next_line && make fclean
		rm -f $(NAME)
		clear

re:	fclean all