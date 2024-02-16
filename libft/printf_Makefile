# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alli <alli@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 12:48:50 by alli              #+#    #+#              #
#    Updated: 2023/11/23 15:20:20 by alli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c\
			ft_putchar.c\
			ft_putnbr.c\
			
OBJECTS = ${SOURCES:.c=.o}

%.o: %.c
	cc ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJECTS}
	ar -rcs ${NAME} ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all
