/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:10:58 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/18 12:34:58 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->img_floor1 = mlx_xpm_file_to_image(game->mlx, "img/tilewater1.xpm",
			&game->tile_size, &game->tile_size);
	game->img_floor2 = mlx_xpm_file_to_image(game->mlx, "img/tilewater2.xpm",
			&game->tile_size, &game->tile_size);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/stone_water.xpm",
			&game->tile_size, &game->tile_size);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx, "img/exit_open.xpm",
			&game->tile_size, &game->tile_size);
	game->img_exit_closed = mlx_xpm_file_to_image(game->mlx,
			"img/exit_closed.xpm", &game->tile_size, &game->tile_size);
	game->img_player_front = mlx_xpm_file_to_image(game->mlx, "img/front.xpm",
			&game->tile_size, &game->tile_size);
	game->img_player_back = mlx_xpm_file_to_image(game->mlx, "img/back.xpm",
			&game->tile_size, &game->tile_size);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx, "img/left.xpm",
			&game->tile_size, &game->tile_size);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx, "img/right.xpm",
			&game->tile_size, &game->tile_size);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"img/collectible.xpm", &game->tile_size, &game->tile_size);
	game->img_collectible2 = mlx_xpm_file_to_image(game->mlx,
			"img/collectible2.xpm", &game->tile_size, &game->tile_size);
}
