/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:30:22 by alli              #+#    #+#             */
/*   Updated: 2024/03/15 16:39:18 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free (grid[i]);
		i++;
	}
	free(grid);
}

int	check_path(t_game *tmp, size_t y, size_t x)
{
	if (tmp->grid[y][x] == '1')
		return (0);
	if (tmp->grid[y][x] == 'C')
		tmp->vinyl--;
	if (tmp->grid[y][x] == 'E')
	{
		tmp->exit_x = 1;
		return (0);
	}
	tmp->grid[y][x] = '1';
	if (check_path(tmp, y + 1, x))
		return (1);
	if (check_path(tmp, y - 1, x))
		return (1);
	if (check_path(tmp, y, x + 1))
		return (1);
	if (check_path(tmp, y, x - 1))
		return (1);
	return (0);
}

void	flood_fill(t_game *game)
{
	size_t	i;
	t_game	tmp;

	tmp.y = game->y;
	tmp.x = game->x;
	tmp.vinyl = game->vinyl;
	tmp.player_x = game->player_x;
	tmp.player_y = game->player_y;
	tmp.exit_x = 0;
	tmp.grid = (char **)malloc(tmp.y * sizeof(char *));
	if (!tmp.grid)
		error_msg("This temporary grid leaked", game, -1);
	i = 0;
	while (i < tmp.y)
	{
		tmp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	check_path(&tmp, tmp.player_y, tmp.player_x);
	if (!(tmp.exit_x == 1 && tmp.vinyl == 0))
		error_msg("this path is reckless, no valid path", game, -1);
	free_grid(tmp.grid, tmp.y);
}
