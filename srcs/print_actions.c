/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:04:54 by alli              #+#    #+#             */
/*   Updated: 2024/03/15 13:11:44 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_collect(t_game *game, int y, int x)
{
	size_t	collect;

	collect = 0;
	x = x * 37;
	y = y * 37;
	while (collect < game->img->vinyl->count)
	{
		if (game->img->vinyl->instances[collect].x == x
			&& game->img->vinyl->instances[collect].y == y)
			game->img->vinyl->instances[collect].enabled = false;
		collect++;
	}
}

void	put_to_screen(t_game *game)
{
	game->img->moves_print = mlx_put_string(game->mlx, "MOVES:",
			40, game->y * 37 - 30);
	if (!mlx_image_to_window(game->mlx, game->img->vinyl,
			175, game->y * 37 - 40))
		error_msg("counter didn't work", game, -1);
	mlx_put_string(game->mlx, ":", 212, game->y * 37 - 30);
}

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->steps);
	if (!moves)
		error_msg("moves not printed", game, -1);
	mlx_delete_image(game->mlx, game->img->moves_nbr);
	game->img->moves_nbr = mlx_put_string(game->mlx, moves,
			100, game->y * 37 - 30);
	ft_printf("MOVES: %d\n", game->steps);
	free(moves);
}

void	print_vinyl(t_game *game)
{
	char	*string;

	string = ft_itoa(game->collected + 1);
	if (!string)
		error_msg("vinyl not printed", game, -1);
	mlx_delete_image(game->mlx, game->img->vinyl_nbr);
	game->img->vinyl_nbr = mlx_put_string(game->mlx, string,
			225, game->y * 37 - 30);
	free(string);
}
