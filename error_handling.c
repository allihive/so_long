/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:30:59 by alli              #+#    #+#             */
/*   Updated: 2024/03/06 12:32:32 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_msg(char *str, t_game *game, int i)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd(str, 2);
    if (i < 0)
        free_grid(game->grid, game->y);
    exit (1);
}