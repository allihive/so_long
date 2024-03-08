/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:31:08 by alli              #+#    #+#             */
/*   Updated: 2024/03/08 14:13:55 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *str, t_game *game, int i) //can remove if needed
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	if (i < 0)
		free_all(game, game->img);
	exit (1);
}

size_t	x_count(char *map)
{
	size_t	i;

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

void	check_game(t_game *game)
{
	print_moves(game);
	if (game->collected == game->vinyl)
	{
		if (mlx_image_to_window (game->mlx, game->img->willow,
				game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
			error_msg
				("X marks the spot where the tree fell apart, tree not loaded",
					game, 1);
		game->grid[game->exit_y][game->exit_x] = '0';
		if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		{
			sleep(1);
			mlx_close_window(game->mlx);
			ft_printf("You helped Taylor collect all her masters!\n");
			ft_printf("And she had a great escape, the London prison break\n");
			ft_printf("she's gone to the place");
			ft_printf(" where all the poets went to write ;)\n");
			ft_printf("SO LONG, LONDON\n");
		}
	}
}

void	free_all(t_game *game, t_img *images)
{
	free_grid(game->grid, game->y);
	mlx_delete_texture(game->tay_down);
	mlx_delete_texture(game->tay_left);
	mlx_delete_texture(game->tay_up);
	mlx_delete_texture(game->tay_right);
	free(images);
	free(game);
}
