/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:39:20 by alli              #+#    #+#             */
/*   Updated: 2024/03/08 13:11:18 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	collect_count(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	collect;

	y = 0;
	collect = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->grid[y][x] == 'C')
				collect++;
			x++;
		}
		y++;
	}
	return (collect);
}

size_t	player_pos(t_game *game, char c)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->grid[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	exit_pos(t_game *game, char c)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->grid[y][x] == 'E')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
