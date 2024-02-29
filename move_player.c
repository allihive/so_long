/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:44:38 by alli              #+#    #+#             */
/*   Updated: 2024/02/29 14:33:12 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    remove_collect(t_game *game, int y, int x)
{
    size_t collect;

    collect = 0;
    x = x * 37;
    y = y * 37;
    while (collect < game->img->vinyl->count)
    {
        if (game->img->vinyl->instances[collect].x == x && game->img->vinyl->instances[collect].y == y)
            game->img->vinyl->instances[collect].enabled = false;
        collect++;
    }
}

t_game    *move_up(t_game *game)
{
    if (game->grid[game->player_y - 1][game->player_x] != '1' && game->grid[game->player_y - 1][game->player_x] != 'E')
    {
        if (game->grid[game->player_y - 1][game->player_x] == 'C')
        {
            remove_collect(game, game->player_y - 1, game->player_x);
            print_vinyl(game);
            game->grid[game->player_y - 1][game->player_x] = '0';
            game->collected += 1;
        }
    game->player_y -= 1;
    game->img->taylor->instances[0].y -= 1 * PIXELS;
    game->steps += 1;
    }
    check_game(game);
    return (game);
}

t_game  *move_down(t_game *game)
{
    if (game->grid[game->player_y + 1][game->player_x] != '1' && game->grid[game->player_y + 1][game->player_x] != 'E')
    {
        if (game->grid[game->player_y + 1][game->player_x] == 'C')
        {
            remove_collect(game, game->player_y + 1, game->player_x);
            print_vinyl(game);
            game->grid[game->player_y + 1][game->player_x] = '0';
            game->collected += 1;
        }
    game->player_y += 1;
    game->img->taylor->instances[0].y += 1 * PIXELS;
    game->steps += 1;
    }
     check_game(game);
     return (game);
}
t_game  *move_left(t_game *game)
{
    if (game->grid[game->player_y][game->player_x - 1] != '1' && game->grid[game->player_y][game->player_x - 1] != 'E')
    {
        if (game->grid[game->player_y][game->player_x - 1] == 'C')
        {
            remove_collect(game, game->player_y, game->player_x - 1);
            print_vinyl(game);
            game->grid[game->player_y][game->player_x - 1] = '0';
            game->collected += 1;
        }
    game->player_x -= 1;
    game->img->taylor->instances[0].x -= 1 * PIXELS;
    game->steps += 1;
    }
    check_game(game);
     return (game);
}

t_game  *move_right(t_game *game)
{
    if (game->grid[game->player_y][game->player_x + 1] != '1' && game->grid[game->player_y][game->player_x + 1] != 'E')
    {
        if (game->grid[game->player_y][game->player_x + 1] == 'C')
        {
            remove_collect(game, game->player_y, game->player_x + 1);
            print_vinyl(game);
            game->grid[game->player_y][game->player_x + 1] = '0';
            game->collected += 1;
        }
    game->player_x += 1;
    game->img->taylor->instances[0].x += 1 * PIXELS;
    game->steps += 1;
    }
     check_game(game);
     return (game); 
}

void    move_player(t_game *game, char axis, char dir)
{
    if (axis == 'y')
    {
        if (dir == 'u')
            move_up(game);
        else
            move_down(game);
    }
    if (axis == 'x')
    {
        if (dir == 'l')
            move_left(game);
        else
            move_right(game);
    }
}

void    move_hook(mlx_key_data_t keydata, void *data)
{
    t_game  *game;

    game = (t_game *) data;
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        move_player(game, 'y', 'u');
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        move_player(game, 'y', 'd');
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        move_player(game, 'x', 'l');
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        move_player (game, 'x', 'r');
}
