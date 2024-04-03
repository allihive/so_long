/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:21:28 by alli              #+#    #+#             */
/*   Updated: 2024/03/08 13:36:03 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*move_up(t_game *game)
{
	if (game->grid[game->player_y - 1][game->player_x] != '1' &&
		game->grid[game->player_y - 1][game->player_x] != 'E')
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

t_game	*move_down(t_game *game)
{
	if (game->grid[game->player_y + 1][game->player_x] != '1' &&
		game->grid[game->player_y + 1][game->player_x] != 'E')
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

t_game	*move_left(t_game *game)
{
	if (game->grid[game->player_y][game->player_x - 1] != '1' &&
		game->grid[game->player_y][game->player_x - 1] != 'E')
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

t_game	*move_right(t_game *game)
{
	if (game->grid[game->player_y][game->player_x + 1] != '1' &&
		game->grid[game->player_y][game->player_x + 1] != 'E')
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
