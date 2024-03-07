/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:29:31 by alli              #+#    #+#             */
/*   Updated: 2024/03/04 13:00:22 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_cobblestones_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*cobblestones;

	cobblestones = mlx_load_png("./game_img/cobblestones.png");
	if (!cobblestones)
		error_msg("walking on broken cobblestones, png hasn't loaded", 0, 1);
	img->cobblestones = mlx_texture_to_image(mlx, cobblestones);
	if (!img->cobblestones)
		error_msg("walking on broken cobblestones, txtre->img not loaded", 0 , 1);
	mlx_delete_texture(cobblestones);
	return (img);
}
t_img *load_taylor_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t   *taylor;
    
    taylor = mlx_load_png("./game_img/tay_front.png");
    if (!taylor)
        error_msg("Taylor can't come to the game right now, png hasn't loaded", 0 ,1);
    img->taylor = mlx_texture_to_image(mlx, taylor);
    if (!img->taylor)
        error_msg("Taylor can't come to the game right now, txtre->img not loaded", 0 ,1);
    mlx_delete_texture(taylor);
    return (img);
}

t_img *load_phone_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t   *phone;
    
    phone = mlx_load_png("./game_img/telephone_booth.png");
    if (!phone)
        error_msg("brand new phone dropped on the cobble stone, png hasn't loaded", 0, 1);
    img->phonebooth = mlx_texture_to_image(mlx, phone);
    if (!img->phonebooth)
        error_msg("brand new phone dropped on the cobble stone, txtre->img not loaded", 0 ,1);
    mlx_delete_texture(phone);
    return (img);
}

t_img *load_vinyl_texture(mlx_t *mlx, t_img *img)//what happened here?
{
    mlx_texture_t   *vinyl;
    
    vinyl = mlx_load_png("./game_img/vinyl.png");
    if (!vinyl)
        error_msg("burned my cd, png hasn't loaded", 0, 1);
    img->vinyl = mlx_texture_to_image(mlx, vinyl);
    if (!img->vinyl)
        error_msg("burned my cd, txtre->img not loaded", 0, 1);
    mlx_delete_texture(vinyl);
    return (img);
}

t_img *load_willow_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t   *willow;
    willow = mlx_load_png("./game_img/willow_tree.png");
    if (!willow)
        error_msg("life was a willow and it bent wrong to the wind, png hasn't loaded", 0, 1);
    img->willow = mlx_texture_to_image(mlx, willow);
    if (!img->willow)
        error_msg("life was a willow and it bent wrong to the wind, txtre->img not loaded", 0, 1);
    mlx_delete_texture(willow);
    return (img);
}

t_img *load_exit_closed_texture(mlx_t *mlx, t_img *img)
{
    mlx_texture_t   *apple;
    apple = mlx_load_png("./game_img/exit_closed.png");
    if (!apple)
        error_msg("The gates are locked, png hasn't loaded", 0, 1);
    img->exit_closed = mlx_texture_to_image(mlx, apple);
    if (!img->exit_closed)
        error_msg("The gates are locked, txtre->img not loaded", 0, 1);
    mlx_delete_texture(apple);
    return (img);
}


void    select_image(t_game *data, size_t y, size_t x)
{
    size_t img;

    img = 30;
    if (data->grid[y][x] == '1')
        if (mlx_image_to_window(data->mlx, data->img->phonebooth, x * PIXELS, y * PIXELS) < 0)
            error_msg("Rust grew between telephones", 0, 1);
    if (data->grid[y][x] == 'P')
        if (mlx_image_to_window(data->mlx, data->img->taylor, x * PIXELS, y * PIXELS) < 0)
            error_msg("Taylor can't come to the window right now", 0, 1);
    if (data->grid[y][x] == 'C')
        if(mlx_image_to_window(data->mlx, data->img->vinyl, x * PIXELS, y * PIXELS) < 0)
            error_msg("burned my cd, my cd hasn't loaded", 0, 1);
    if (data->grid[y][x] == 'E')
        if(mlx_image_to_window(data->mlx, data->img->exit_closed, x * PIXELS, y * PIXELS) < 0)
            error_msg("You're not out of the woods yet", 0, 1);
}


void    render_map(t_game *game)
{
    size_t  y;
    size_t  x;

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
void   fill_background(t_game *game)
{
    size_t y;
    size_t x;
    
    y = 0;
    x = 0;//? not sure if this is correct
    while (y < game->y)
    {
        x = 0;
        while (x < game->x)
        {
            if (mlx_image_to_window(game->mlx, game->img->cobblestones, x * PIXELS, y * PIXELS) < 0)
                error_msg("just another picture that burned", 0, 1);
            x++;
        }
        y++;
    }
}