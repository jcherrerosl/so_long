/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:21:11 by juaherre          #+#    #+#             */
/*   Updated: 2024/12/06 11:59:13 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	place_enemies(t_game *game, char **map)
{
	int	max_enemies;
	int	placed_enemies;
	int	y;
	int	x;

	max_enemies = (game->map_height + game->map_width) / 2;
	placed_enemies = 0;
	y = 1;
	while (map[y + 1] && placed_enemies < max_enemies)
	{
		x = 1;
		while (map[y][x + 1] && placed_enemies < max_enemies)
		{
			if (map[y][x] == '0')
			{
				map[y][x] = 'X';
				if (check_path(map, game->player_x, game->player_y))
					placed_enemies++;
				else
					map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
