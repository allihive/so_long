/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:43:34 by alli              #+#    #+#             */
/*   Updated: 2024/03/15 16:48:45 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tay_direction(t_game *game, char dir)
{
	if (dir == 'u')
		mlx_draw_texture(game->img->taylor, game->tay_up, 0, 0);
	if (dir == 'l')
		mlx_draw_texture(game->img->taylor, game->tay_left, 0, 0);
	if (dir == 'd')
		mlx_draw_texture(game->img->taylor, game->tay_down, 0, 0);
	if (dir == 'r')
		mlx_draw_texture(game->img->taylor, game->tay_right, 0, 0);
}

t_img	*load_exit_closed_texture(t_game *game, t_img *img)
{
	mlx_texture_t	*apple;

	apple = mlx_load_png("./game_img/exit_closed.png");
	if (!apple)
		error_msg("The gates are locked, exit png hasn't loaded", 0, 1);
	img->exit_closed = mlx_texture_to_image(game->mlx, apple);
	if (!img->exit_closed)
		error_msg("The gates are locked, exit txtre->img not loaded", 0, 1);
	mlx_delete_texture(apple);
	return (img);
}

void	select_image(t_game *data, size_t y, size_t x)
{
	if (data->grid[y][x] == '1')
		if (mlx_image_to_window(data->mlx, data->img->phonebooth,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("Rust grew between telephones, img->window fail",
				data, -1);
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window(data->mlx, data->img->taylor,
				x * PIXELS, y * PIXELS) < 0)
			error_msg
				("Taylor can't come to the window right now, img->window fail",
					data, -1);
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window(data->mlx, data->img->vinyl,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("burned my cd, img->window fail", data, -1);
	if (data->grid[y][x] == 'E')
		if (mlx_image_to_window(data->mlx, data->img->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			error_msg
				("You're not out of the woods yet, img->window fail", data, -1);
}

void	render_map(t_game *game)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			select_image(game, y, x);
			x++;
		}
		y++;
	}
}

void	fill_background(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (mlx_image_to_window(game->mlx, game->img->cobblestones,
					x * PIXELS, y * PIXELS) < 0)
				error_msg("just another picture that burned, bckgrd not filled",
					game, -1);
			x++;
		}
		y++;
	}
}
