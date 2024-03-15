/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:30:20 by alli              #+#    #+#             */
/*   Updated: 2024/03/15 13:01:15 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_col_wall(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->y)
	{
		if (game->grid[i][0] != '1')
			error_msg("the delicate walls are leaking!", game, -1);
		if (game->grid[i][game->x - 1] != '1')
			error_msg("the delicate walls are leaking!", game, -1);
		i++;
	}
}

void	check_row_wall(t_game *game)
{
	int	i;

	i = 0;
	while (game->grid[0][i])
	{
		if (game->grid[0][i] != '1')
			error_msg("the delicate walls are leaking!", game, -1);
		if (game->grid[game->y - 1][0] != '1')
			error_msg("the delicate walls are leaking!", game, -1);
		i++;
	}
}

void	check_walls(t_game *map)
{
	check_col_wall(map);
	check_row_wall(map);
}

void	check_col_exit_play(char *map)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'P')
			p++;
		i++;
	}
	if (c < 1 || e != 1 || p != 1)
	{
		free(map);
		error_msg("Map things are the incorrect number", 0, 1);
	}
}

void	check_map_type(char *map)
{
	char	*ber;
	int		len;
	int		cmp;

	cmp = 0;
	len = ft_strlen(map);
	ber = ".ber";
	cmp = ft_strncmp(&map[len - 4], ber, 4);
	if (cmp != 0)
		error_msg("dear reader: this is not the correct file type", 0, 1);
}
