/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:30:24 by alli              #+#    #+#             */
/*   Updated: 2024/03/20 13:05:41 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_other_tay_textures(t_game *game)
{
	game->tay_down = mlx_load_png("./game_img/tay_front.png");
	if (!game->tay_down)
		error_msg("Taylor can't come to the game right now, txtre not loaded",
			game, -1);
	game->tay_up = mlx_load_png("./game_img/tay_back.png");
	if (!game->tay_up)
		error_msg("Taylor can't come to the game right now,  txtre not loaded",
			game, -1);
	game->tay_left = mlx_load_png("./game_img/tay_left.png");
	if (!game->tay_left)
		error_msg("Taylor can't come to the game right now, txtre not loaded",
			game, -1);
	game->tay_right = mlx_load_png("./game_img/tay_right.png");
	if (!game->tay_right)
		error_msg("Taylor can't come to the game right now, txtre not loaded",
			game, -1);
}

t_game	*init_struct(char **grid)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_msg("This game went down in flames, not initialized",
			game, 1);
	game->x = x_count(grid[0]);
	game->y = y_count(grid);
	game->grid = grid;
	game->steps = 0;
	game->vinyl = collect_count(game);
	game->player_x = player_pos(game, 'x');
	game->player_y = player_pos(game, 'y');
	game->exit_x = exit_pos(game, 'x');
	game->exit_y = exit_pos(game, 'y');
	load_other_tay_textures(game);
	return (game);
}

t_game	*valid_map(char *map)
{
	t_game	*game_info;
	char	*map_read;
	char	**map_array;

	map_read = read_map(map);
	empty_map(map_read);
	empty_line(map_read);
	check_char(map_read);
	check_col_exit_play(map_read);
	map_array = create_map(map_read);
	if (!map_array)
		error_msg("The map_array memory not allocated", 0, 1);
	map_is_rctangl(map_array);
	check_map_size(map_array);
	game_info = init_struct(map_array);
	check_walls(game_info);
	flood_fill(game_info);
	free(map_read);
	return (game_info);
}

t_img	*init_img_struct(t_game *game)
{
	t_img	*pics;

	pics = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!pics)
		error_msg("pics not loaded", game, -1);
	pics = load_cobblestones_texture(game, pics);
	pics = load_taylor_texture(game, pics);
	pics = load_vinyl_texture(game, pics);
	pics = load_phone_texture(game, pics);
	pics = load_willow_texture(game, pics);
	pics = load_exit_closed_texture(game, pics);
	return (pics);
}
