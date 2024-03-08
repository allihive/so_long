/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:26:05 by alli              #+#    #+#             */
/*   Updated: 2024/03/08 14:40:46 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_img	*images;

	if (argc != 2)
		error_msg
			("But it would've been fun, if you would've put 2 args", 0, 1);
	check_map_type(argv[1]);
	game = valid_map(argv[1]);
	game->mlx = mlx_init(game->x * PIXELS, game->y * PIXELS, "so_long", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	images = init_img_struct(game->mlx);
	game->img = images;
	fill_background(game);
	render_map(game);
	put_to_screen(game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_all(game, images);
	return (EXIT_SUCCESS);
}
