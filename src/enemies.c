/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:21:11 by juaherre          #+#    #+#             */
/*   Updated: 2024/12/06 12:33:27 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_walkable(char tile)
{
	if (tile == '0' || tile == 'C' || tile == 'E')
		return (1);
	return (0);
}

void	place_enemies(t_game *game, char **map)
{
	int	max_enemies;
	int	placed_enemies;
	int	y;
	int	x;

	placed_enemies = 0;
	max_enemies = (game->map_height * game->map_width);
	y = 1;
	while (y < game->map_height - 1)
	{
		x = 1;
		while (x < game->map_width - 1)
		{
			if (map[y][x] == '0' && (x + y) % 5 == 0 && placed_enemies < max_enemies)
			{
				map[y][x] = 'X';
				if (check_path(map, game->player_x, game->player_y) == 1)
					placed_enemies++;
				else
					map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
