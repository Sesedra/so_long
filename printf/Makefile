# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 10:15:49 by srabeman          #+#    #+#              #
#    Updated: 2025/01/13 09:41:11 by srabeman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_putchar.c ft_putstr.c ft_putnbr.c ft_putuns_nbr.c \
					ft_putaddress.c ft_puthex_low.c ft_puthex_upp.c ft_handle_format.c \
					ft_printf.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -Iincludes -I. 

NAME			= libftprintf.a

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
