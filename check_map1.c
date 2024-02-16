#include "so_long.h"

void    check_walls(t_game *map)
{
	check_col_wall(map);
	check_row_wall(map);
    return (1);
}

void	check_col_wall(t_game *game)
{
    int i;

    i = 0;
    while (game->grid[i][0])
    {
        if (game->grid[i][0] != '1')
            error_msg("the delicate walls are leaking!");
        if (game->grid[game->x - 1][0] != '1')
            error_msg("the delicate walls are leaking!");
        i++;
    }
    return (1);
}
void	check_row_wall(t_game *game)
{
    int i;

    i = 0;
    while (game->grid[0][i])
    {
        if (game->grid[0][i] != '1')
            error_msg("the delicate walls are leaking!");
        if (game->grid[game->y - 1][0] != '1')
            error_msg("the delicate walls are leaking!");
        i++;
    }
    return (1);
}

void	check_col_exit_play(char *map)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'P')
			p++;
		i++;
	}
	if (c < 1 || e != 1 || p != 1)
		error_msg("not enough toys to play with :("); //false not a valid map
}

void	check_map_type(char *map)
{
    char *ber;
    int len;
    int cmp;

    cmp = 0;
    len = ft_strlen(map);
    ber = ".ber";
    cmp = ft_strncmp(&map[len - 4], ber, 4);
    printf("%d\n", cmp);
    if (cmp != 0)
        error_msg("dear reader: this is not the correct file type"); //false not a ber file
}

char *read_map(char *file)
{
	char	*line;
    char    *map;
    int     fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("dear reader: error reading file, try another one");
    map = ft_calloc(1, 1);
    if (!map)
        return (NULL);
    while (1)
    {
        line = get_next_line(fd);
        if (line)
        {
            map = ft_strjoin(map, line);
            if (!map)
                return (NULL);
            free(line);
        }
        else
            break;
    }
    close (fd);
    return (map);
}

char    **create_map(char *map) //now I have a 2D array
{
    char **grid;
    char *read;

    read = read_map(map);
    grid = ft_split(read, '\n');
    if (!grid)
    {
        free(grid);
        return (NULL);
    }
    return (grid);
}
 //have a validate map function
    //check if the map type is correct .ber
    //check if the map can be read and created
    //check for an empty map
    //check_char
    //check empty line
    //check for rectangle
    //check walls
    //check check valid path

int main ()
{
    char *map = "map_1.ber";
	char *read = read_map(map);
    char **create = create_map(read);
    // printf("%p\n", read);
    printf("%d\n", check_walls(*create));
}