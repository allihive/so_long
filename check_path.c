#include "so_long.h"

void    free_grid(char **grid, size_t height)
{
    int i;

    i = 0;
    while (i < height)
    {
        free (grid[i]);
        i++;
    }
    free(grid);
}

int check_path(t_game *tmp, int x, int y)
{
    if (tmp->grid[y][x] == '1')
        return (0);
    if (tmp->grid[y][x] == 'C')
        tmp->collect--;
    if (tmp->grid[y][x] == 'E')
    {
        tmp->exit_x = 1;
        return (0);
    }
    tmp->grid[y][x] = 'F';
    if(check_path(tmp, y - 1, x));
        return (1);
    if(check_path(tmp, y + 1, x));
        return (1);
    if(check_path(tmp, y, x - 1));
        return (1);
    if (check_path(tmp, y, x + 1));
        return (1);
    return (0);
}
int flood_fill(t_game *game)
{
    size_t  i;
    t_game tmp;

    i = 0;
    tmp.y = game->y;
    tmp.x = game->x;
    tmp.collect = game->collect;
    tmp.player_x = game->player_x;
    tmp.player_y = game->player_y;
    tmp.exit_x = 0;
    tmp.grid = (char**)malloc(tmp.y * sizeof(char *));
    if (!tmp.grid)
        error_msg("these memories did not follow");
    while (i < tmp.y)
    {
        tmp.grid[i] = ft_strdup(game->grid[i]);
        i++;
    }
    check_path(&tmp, tmp.player_x, tmp.player_y);
    if (!(tmp.exit_x == 1 && tmp.collect == 0))
        error_msg("this path is reckless");
    free_grid(tmp.grid, tmp.height);
}
