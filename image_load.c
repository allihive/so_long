/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:29:31 by alli              #+#    #+#             */
/*   Updated: 2024/03/08 14:34:15 by alli             ###   ########.fr       */
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
		error_msg("walking on broken cobblestones, txtre->img not loaded",
			0, 1);
	mlx_delete_texture(cobblestones);
	return (img);
}

t_img	*load_taylor_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*taylor;

	taylor = mlx_load_png("./game_img/tay_front.png");
	if (!taylor)
		error_msg ("Taylor can't come to the game right now, png hasn't loaded",
			0, 1);
	img->taylor = mlx_texture_to_image(mlx, taylor);
	if (!img->taylor)
		error_msg
			("Taylor can't come to the game right now, txtre->img not loaded",
				0, 1);
	mlx_delete_texture(taylor);
	return (img);
}

t_img	*load_phone_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*phone;

	phone = mlx_load_png("./game_img/telephone_booth.png");
	if (!phone)
		error_msg
			("Phone dropped on the cobble stone, png hasn't loaded",
				0, 1);
	img->phonebooth = mlx_texture_to_image(mlx, phone);
	if (!img->phonebooth)
		error_msg
			("Phone dropped on the cobblestone, txtre->img not loaded",
				0, 1);
	mlx_delete_texture(phone);
	return (img);
}

t_img	*load_vinyl_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*vinyl;

	vinyl = mlx_load_png("./game_img/vinyl.png");
	if (!vinyl)
		error_msg("burned my cd, png hasn't loaded", 0, 1);
	img->vinyl = mlx_texture_to_image(mlx, vinyl);
	if (!img->vinyl)
		error_msg("burned my cd, txtre->img not loaded", 0, 1);
	mlx_delete_texture(vinyl);
	return (img);
}

t_img	*load_willow_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*willow;

	willow = mlx_load_png ("./game_img/willow_tree.png");
	if (!willow)
		error_msg
			("willow bent the wrong way, png hasn't loaded",
				0, 1);
	img->willow = mlx_texture_to_image (mlx, willow);
	if (!img->willow)
		error_msg
			("willow bent the wrong way, txtre->img not loaded",
				0, 1);
	mlx_delete_texture (willow);
	return (img);
}
