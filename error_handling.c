/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:29:42 by alli              #+#    #+#             */
/*   Updated: 2024/03/15 16:43:02 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_end(t_game *game, t_img *images)
{
	free_grid(game->grid, game->y);
	mlx_delete_texture(game->tay_down);
	mlx_delete_texture(game->tay_left);
	mlx_delete_texture(game->tay_up);
	mlx_delete_texture(game->tay_right);
	free(images);
	free(game);
}

void	error_image(t_game *game)
{
	if (game->img->taylor)
		mlx_delete_image(game->mlx, game->img->taylor);
	if (game->img->cobblestones)
		mlx_delete_image(game->mlx, game->img->cobblestones);
	if (game->img->vinyl)
		mlx_delete_image(game->mlx, game->img->vinyl);
	if (game->img->phonebooth)
		mlx_delete_image(game->mlx, game->img->phonebooth);
	if (game->img->willow)
		mlx_delete_image(game->mlx, game->img->willow);
	if (game->img->exit_closed)
		mlx_delete_image(game->mlx, game->img->exit_closed);
	if (game->img->vinyl_nbr)
		mlx_delete_image(game->mlx, game->img->vinyl_nbr);
	if (game->img->moves_nbr)
		mlx_delete_image(game->mlx, game->img->moves_nbr);
	if (game->img->moves_print)
		mlx_delete_image(game->mlx, game->img->moves_print);
}

void	error_msg(char *str, t_game *game, int i)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	if (i < 0)
	{
		if (game->img)
			error_image(game);
		free_end(game, game->img);
	}
	exit (1);
}
