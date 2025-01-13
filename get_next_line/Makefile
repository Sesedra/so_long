# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 08:00:38 by srabeman          #+#    #+#              #
#    Updated: 2025/01/13 08:04:05 by srabeman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line_utils.c get_next_line.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
FLAGS	= -Wall -Werror -Wextra -Iincludes -I.

NAME	= get_next_line.a

%.o:			%.c
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all 


.PHONY:			all clean fclean re