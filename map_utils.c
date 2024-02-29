/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:31:08 by alli              #+#    #+#             */
/*   Updated: 2024/02/29 14:34:35 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t x_count(char *map)
{
    size_t i;

    i = 0;
    while (map[i] != '\n' && map[i])
        i++;
    return (i);
}

size_t	y_count(char **grid)
{
	size_t	y;

	y = 0;
    while (grid[y])
        y++;
	return (y);
}

void    check_game(t_game *game)
{
    //print_moves
    if(game->collected == game->vinyl)
    {
        if(mlx_image_to_window(game->mlx, game->img->willow, game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
            error_msg("X marks the spot where the tree fell apart");
        game->grid[game->exit_y][game->exit_x] = '0';
        if (game->player_x == game->exit_x && game->player_y == game->exit_y)
        {
            sleep(1);
            ft_printf("You helped Taylor collect all her masters!\n");
            ft_printf("And she had a great escape, the London prison break\n");
            ft_printf("she's gone to the place where all the poets went to die\n");
            ft_printf("SO LONG LONDON\n");
        }
    }
}