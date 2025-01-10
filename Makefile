SRCS 	= main.c

NAME	= so_long

CC 	= gcc
FLAGS	= -Wall -Werror -Wextra -g -Iincludes
MLX_FLAGS	= -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all:	$(NAME)
$(NAME):
		@cd printf && make	
		$(CC) $(SRCS) $(FLAGS) $(MLX_FLAGS) printf/libftprintf.a -o $(NAME)

		
clean:
		@cd printf && make clean

fclean:
		@cd printf && make fclean
		rm -f $(NAME)
		clear

re:	fclean all