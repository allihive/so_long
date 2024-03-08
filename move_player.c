/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:44:38 by alli              #+#    #+#             */
/*   Updated: 2024/03/08 13:25:13 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, char axis, char dir)
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

void	change_dir(t_game *game, char axis, char dir)
{
	move_player(game, axis, dir);
	tay_direction(game, dir);
}

void	move_hook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		change_dir(game, 'y', 'u');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		change_dir(game, 'y', 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		change_dir(game, 'x', 'l');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		change_dir (game, 'x', 'r');
}
