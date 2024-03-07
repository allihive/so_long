/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:04:54 by alli              #+#    #+#             */
/*   Updated: 2024/03/04 14:14:15 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_to_screen(t_game *game)
{
    game->img->moves_print = mlx_put_string(game->mlx, "MOVES:", 40, game->y * 37 - 30);
    mlx_image_to_window(game->mlx, game->img->vinyl, 175, game->y * 37 - 40);
    mlx_put_string(game->mlx, ":", 212, game->y * 37 - 30);
}
void    print_moves(t_game *game) //in check_game
{
    char *moves;

    moves = ft_itoa(game->steps);
    mlx_delete_image(game->mlx, game->img->moves_nbr);
    game->img->moves_nbr = mlx_put_string(game->mlx, moves, 100, game->y * 37 - 30);
    ft_printf("MOVES: %d\n", game->steps);//leaking here
    free(moves);
}

void print_vinyl(t_game *game) //in move_hook
{
    char *string;

    string = ft_itoa(game->collected + 1);
    mlx_delete_image(game->mlx, game->img->vinyl_nbr);
    game->img->vinyl_nbr = mlx_put_string(game->mlx, string, 225, game->y * 37 - 30);
    free(string);
}