/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:21:11 by juaherre          #+#    #+#             */
/*   Updated: 2024/12/06 23:09:06 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	place_enemies(t_game *game, char **map)
{
	int	placed_enemies;
	int	y;
	int	x;

	placed_enemies = 0;
	y = 1;
	while (y < game->map_height - 1)
	{
		x = 1;
		while (x < game->map_width - 1)
		{
			if (map[y][x] == '0' && placed_enemies < (game->map_width
					* game->map_height) / 3 && (x + y) % 5 == 0)
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

void	ft_die(t_game *game)
{
	ft_printf("You died! ☠️\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
