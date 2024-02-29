/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:30:38 by alli              #+#    #+#             */
/*   Updated: 2024/02/23 09:08:01 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_map(char *map)
{
    size_t i;

    i = 0;
    if (!map[i])
        error_msg("the map is empty");
}

void	empty_line(char *map)
{
	size_t i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
            error_msg("empty line detected");
		i++;
	}
}

int check_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'C' || map[i] == 'E' || map[i] == '1' 
			|| map[i] == '0' || map[i] == 'P' || map[i] == '\n')
			i++;
		else
			error_msg("extraneous behavior detected, try another map");
	}
	return (1);
}

int	map_is_rctangl(char *map)
{
	int	row;
	int	i;
    int nl;

    nl = 0;
    row = y_count(&map);
    i = y_count(&map);
	while (map[i])
	{
        if (i == row)
            i++;
		if (map[i] == '\n')
		{
            nl++;
			if ((i - nl) % row == 0)
                i++;
            else
                return (0);
		}
		i++;
	}
	return (1);
}
