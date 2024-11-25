/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:10:58 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/25 11:29:14 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_game *game)
{
	game->img_floor1 = mlx_xpm_file_to_image(game->mlx,
			"assets/img/tilewater1.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_floor1)
		ft_printerror("Error loading img_floor1\n");
	game->img_floor2 = mlx_xpm_file_to_image(game->mlx,
			"assets/img/tilewater2.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_floor2)
		ft_printerror("Error loading img_floor2\n");
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/img/stone_water.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_wall)
		ft_printerror("Error loading img_wall\n");
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"assets/img/exit_open.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_exit_open)
		ft_printerror("Error loading img_exit_open\n");
	game->img_exit_closed = mlx_xpm_file_to_image(game->mlx,
			"assets/img/exit_closed.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_exit_closed)
		ft_printerror("Error loading img_exit_closed\n");
	game->img_player_front = mlx_xpm_file_to_image(game->mlx,
			"assets/img/front.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_player_front)
		ft_printerror("Error loading img_player_front\n");
	game->img_player_back = mlx_xpm_file_to_image(game->mlx,
			"assets/img/back.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_player_back)
		ft_printerror("Error loading img_player_back\n");
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"assets/img/left.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_player_left)
		ft_printerror("Error loading img_player_left\n");
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"assets/img/right.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_player_right)
		ft_printerror("Error loading img_player_right\n");
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/img/collectible.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_collectible)
		ft_printerror("Error loading img_collectible\n");
	game->img_collectible2 = mlx_xpm_file_to_image(game->mlx,
			"assets/img/collectible2.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_collectible2)
		ft_printerror("Error loading img_collectible2\n");
}
