/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:30:38 by alli              #+#    #+#             */
/*   Updated: 2024/03/08 14:31:18 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_map(char *map)
{
	size_t	i;

	i = 0;
	if (!map[i])
		error_msg("the map is empty", 0, 1);
}

void	empty_line(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
			error_msg("empty line detected", 0, 1);
		i++;
	}
	if (map[i - 1] == '\n')
		error_msg("empty line detected", 0, 1);
}

int	check_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'C' || map[i] == 'E' || map[i] == '1'
			|| map[i] == '0' || map[i] == 'P' || map[i] == '\n')
			i++;
		else
		{
			free(map);
			error_msg("extraneous characters detected, try another map", 0, 1);
		}
	}
	return (1);
}

void	map_is_rctangl(char **grid)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = x_count(grid[i]);
	while (grid[i])
	{
		if (x_count(grid[i]) != len)
		{
			free_grid(grid, y_count(grid));
			error_msg("Map is not a rectangle", 0, 1);
		}
		i++;
	}
}

void	check_map_size(char **grid)
{
	size_t	y_max;
	size_t	x_max;
	size_t	y_counter;
	size_t	x_counter;

	y_max = 35;
	x_max = 69;
	y_counter = y_count(grid);
	x_counter = x_count(grid[0]);
	if (y_counter > y_max)
	{
		free_grid(grid, y_count(grid));
		error_msg("Your map was bigger than the whole screen", 0, 1);
	}
	if (x_counter > x_max)
	{
		free_grid(grid, y_count(grid));
		error_msg("Your map was bigger than the whole screen", 0, 1);
	}
}
