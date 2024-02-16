NAME = so_long

CFLAGS =  -Wall -Wextra -Werror -I./libft -g
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

SRCS = check_map1.c \
		check_map2.c \
		check_path.c \
		error_handling.c \
		initialize_struct.c \
		map_utils.c \

OBJECTS = ${SRCS:.c=.o}

%.o: %.c
	cc ${CFLAGS} -c $< -o $@

all: ${NAME} ${LIBFT}

${NAME}: ${OBJECTS} ${LIBFT}
	 cc ${CFLAGS} ${OBJECTS} -L$(LIBFT_DIR) -lft -o ${NAME} 

${LIBFT}:
	make -C $(LIBFT_DIR)
clean:
	rm -f ${OBJECTS} ${LIBFT}
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f ${NAME}
	@make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
