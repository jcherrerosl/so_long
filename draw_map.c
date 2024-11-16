/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:21:35 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/16 19:24:21 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(t_game *game)
{
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/bush.xpm",
            &game->tile_size, &game->tile_size);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "img/fond.xpm",
            &game->tile_size, &game->tile_size);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "img/imgexit.xpm",
            &game->tile_size, &game->tile_size);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "img/npc.xpm",
            &game->tile_size, &game->tile_size);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "img/poke.xpm",
            &game->tile_size, &game->tile_size);
}


void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int i, j;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_tile(game, game->map[i][j], j, i);
			j++;
		}
		i++;
	}
}
