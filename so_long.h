#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_game
{
    char **grid;
    size_t x;
    size_t y;
    size_t collect;
    size_t steps;
    size_t player_x;
    size_t player_y;
    size_t exit_x;
    size_t exit_y;
} t_game;

void	check_map_type(char *map);
int		check_char(char *map);
void	check_col_exit_play(char *map);
void	check_col_wall(t_game *game);
void	check_row_wall(t_game *game);
void    check_walls(char *map);
int     column_count(char *map);
void	error_msg(char *str);
void	empty_line(char *map);
int		map_is_rctangl(char *map);
char	*read_map(char *file);
int	    row_count(char *map);

#endif
