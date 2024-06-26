/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:51:30 by alli              #+#    #+#             */
/*   Updated: 2024/03/20 14:01:38 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

# define PIXELS 37

typedef struct s_img
{
	mlx_image_t	*taylor;
	mlx_image_t	*cobblestones;
	mlx_image_t	*vinyl;
	mlx_image_t	*phonebooth;
	mlx_image_t	*willow;
	mlx_image_t	*exit_closed;
	mlx_image_t	*vinyl_nbr;
	mlx_image_t	*moves_nbr;
	mlx_image_t	*moves_print;
}	t_img;

typedef struct s_game
{
	char			**grid;
	size_t			x;
	size_t			y;
	size_t			vinyl;
	size_t			steps;
	size_t			collected;
	size_t			player_x;
	size_t			player_y;
	size_t			exit_x;
	size_t			exit_y;
	mlx_t			*mlx;
	t_img			*img;
	mlx_texture_t	*tay_down;
	mlx_texture_t	*tay_up;
	mlx_texture_t	*tay_right;
	mlx_texture_t	*tay_left;
}	t_game;

/*image loading*/
t_img	*init_img_struct(t_game *game);
void	fill_background(t_game *game);
t_img	*load_cobblestones_texture(t_game *game, t_img *img);
t_img	*load_taylor_texture(t_game *game, t_img *img);
void	select_image(t_game *data, size_t y, size_t x);
void	render_map(t_game *game);
t_img	*load_phone_texture(t_game *game, t_img *img);
t_img	*load_vinyl_texture(t_game *game, t_img *img);
t_img	*load_willow_texture(t_game *game, t_img *img);
t_img	*load_exit_closed_texture(t_game *game, t_img *img);

/*moves*/
t_game	*move_down(t_game *game);
t_game	*move_up(t_game *game);
t_game	*move_right(t_game *game);
t_game	*move_left(t_game *game);
void	move_player(t_game *game, char axis, char dir);
void	move_hook(mlx_key_data_t keydata, void *data);
void	check_game(t_game *game);
void	change_dir(t_game *game, char axis, char dir);
void	print_moves(t_game *game);
void	tay_direction(t_game *game, char dir);

/*print to screen*/
void	print_vinyl(t_game *game);
void	put_to_screen(t_game *game);
void	print_moves(t_game *game);
void	remove_collect(t_game *game, int y, int x);

/*error-handling*/
void	error_image(t_game *game);
void	free_end(t_game *game, t_img *images);
void	error_msg(char *str, t_game *game, int i);
void	free_grid(char **grid, size_t height);

/*map validation*/
int		check_char(char *map);
void	check_col_exit_play(char *map);
void	check_col_wall(t_game *game);
void	check_row_wall(t_game *game);
void	check_map_type(char *map);
void	check_map_size(char **grid);
void	check_walls(t_game *map);
size_t	collect_count(t_game *game);
char	**create_map(char *map);
void	empty_line(char *map);
void	empty_map(char *map);
size_t	exit_pos(t_game *game, char c);
void	flood_fill(t_game *game);
t_game	*init_struct(char **grid);
void	map_is_rctangl(char **grid);
size_t	player_pos(t_game *game, char c);
char	*read_map(char *file);
t_game	*valid_map(char *map);
size_t	x_count(char *map);
size_t	y_count(char **grid);

#endif
