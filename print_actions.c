/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:04:54 by alli              #+#    #+#             */
/*   Updated: 2024/02/29 15:12:39 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y);

void    put_to_screen(t_game *game)
{
    game->img->moves_print = mlx_put_string(game->mlx, "MOVES:", 16, game->y * PIXELS);
    mlx_image_to_window(game->mlx, game->img->vinyl_nbr, 140, game->y * PIXELS - 44);
    mlx_put_string(game->mlx, ":", 160, game->y * PIXELS - 44);
}
void    print_moves(t_game *game)
{
    char *moves;

    moves = ft_itoa(game->steps);
    mlx_delete_image(game->mlx, game->img->moves_nbr);
    game->img->moves_nbr = mlx_put_string(game->mlx, moves, 175, game->y * 37 -16);
    
}

void print_vinyl(t_game *game)
{
    char *string;

    string = ft_itoa(game->collected + 1);
    mlx_delete_image(game->mlx, game->img->vinyl_nbr); //vinyl_nbr instead of vinyl
    game->img->vinyl_nbr = mlx_put_string(game->mlx, string, 175, game->y * 37 -16);
    free(string);
}