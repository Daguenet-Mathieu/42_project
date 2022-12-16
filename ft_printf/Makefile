# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madaguen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 20:04:28 by madaguen          #+#    #+#              #
#    Updated: 2022/11/24 15:55:53 by madaguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c		\
			ft_putchar.c		\
			ft_putstr.c			\
			handdle_letter.c	\
			isinchar.c			\
			ft_put_unsigned.c	\
			ft_putnbr.c			\
			ft_hex.c			
	
OBJS		= ${SRCS:.c=.o}
HEADER		= ft_printf.h
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a

%.o: %.c ${SRCS}
		$(CC) $(FLAGS) -c -o $@ $<

$(NAME): ${OBJS} ${HEADER}
		ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
		rm -f ${OBJS} ${OBJS_BONUS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all bonus clean fclean re
