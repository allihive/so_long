NAME = so_long

CFLAGS =  -Wall -Wextra -Werror -I./libft -g #remember to delete -g before eval
MLX42FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
LIBFT_INCLUDE = -I ${LIBFT_DIR}

MLX_DIR = ./MLX42/build
MLX42 = ./MLX42/build/libmlx42.a
LD_FLAGS = -L/Users/$(USER)/.brew/opt/glfw/lib/

# INCLUDE = -I ./include $(MLX_DIR)/include
INCLUDES = -I/opt/X11/include -Imlx

SRCS = check_map1.c \
		check_map2.c \
		check_path.c \
		error_handling.c \
		initialize_struct.c \
		item_coordinates.c \
		miscellaneous.c \
		move_player.c \
		print_actions.c \
		so_long.c \
		image_load.c \

OBJ = ${SRCS:.c=.o}

all: makelibft ${NAME}

makelibft:
	make -C ${LIBFT_DIR}

${NAME}: ${LIBFT} ${MLX42} ${OBJ} 
	cc ${CFLAGS} ${OBJ} ${LIBFT_INCLUDE} $(MLX42) ${MLX42FLAGS} ${LD_FLAGS} -L${LIBFT_DIR} ${INCLUDES} -lft -o ${NAME} 
	##gcc -g -fsanitize=address -fno-omit-frame-pointer 
%.o: %.c
	cc ${CFLAGS} ${INCLUDES} -c $< -o $@

${LIBFT}:
	make -C ./libft

${MLX42}:
	make -C ./MLX42
clean:
	rm -f ${OBJ}
	@make clean -C ${LIBFT_DIR}

fclean: clean
	rm -f ${NAME}
	@make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
	rm -f ${NAME}
