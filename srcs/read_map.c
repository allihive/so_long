/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:33:34 by alli              #+#    #+#             */
/*   Updated: 2024/03/20 13:41:25 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *file)
{
	char	*line;
	char	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_msg("dear reader: error reading file, try another one", 0, 1);
	map = ft_calloc(1, 1);
	if (!map)
		error_msg("map wasn't allocated", 0, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map = ft_strjoin(map, line);
			if (!map)
				error_msg("map not joined", 0, 1);
			free(line);
		}
		else
			break ;
	}
	close (fd);
	return (map);
}

char	**create_map(char *map) //now I have a 2D array
{
	char	**grid;

	grid = ft_split(map, '\n');
	if (!grid)
	{
		free(map);
		return (NULL);
	}
	return (grid);
}
