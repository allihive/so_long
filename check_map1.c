/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:30:20 by alli              #+#    #+#             */
/*   Updated: 2024/03/01 15:28:49 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_col_wall(t_game *game)
{
    size_t i;

    i = 0;
    while (i < game->y)
    {
        if (game->grid[i][0] != '1')
            error_msg("the delicate walls are leaking!");
        if (game->grid[i][game->x - 1] != '1')
            error_msg("the delicate walls are leaking!");
        i++;
    }
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
}
void    check_walls(t_game *map)
{
	check_col_wall(map);
	check_row_wall(map);
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
    if (cmp != 0)
        error_msg("dear reader: this is not the correct file type"); //false not a ber file
}

char *read_map(char *file)
{
	char	*line;
    char    *map;
    char    *temp;
    int     fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_msg("dear reader: error reading file, try another one");
    map = ft_calloc(1, 1);
    if (!map)
        return (NULL);
    while (1)
    {
        line = get_next_line(fd);
        if (line)
        {
            temp = map;
            map = ft_strjoin(map, line);
            if (!map)
                return (NULL);
            free(temp);
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

    grid = ft_split(map, '\n');
    if (!grid)
    {
        //printf("what happened here");
        free(grid);
        return (NULL);
    }
    return (grid);
}
