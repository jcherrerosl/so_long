/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:10:58 by juaherre          #+#    #+#             */
/*   Updated: 2024/12/06 10:26:29 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_floor_images(t_game *game)
{
	game->img_floor1 = mlx_xpm_file_to_image(game->mlx,
			"assets/img/tilewater1.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_floor1)
		ft_printerror("Error loading img_floor1\n");
	game->img_floor2 = mlx_xpm_file_to_image(game->mlx,
			"assets/img/tilewater2.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_floor2)
		ft_printerror("Error loading img_floor2\n");
}

void	load_wall_and_exit_images(t_game *game)
{
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
}

void	load_player_images(t_game *game)
{
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
}

void	load_collectible_and_enemy_images(t_game *game)
{
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/img/collectible.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_collectible)
		ft_printerror("Error loading img_collectible\n");
	game->img_collectible2 = mlx_xpm_file_to_image(game->mlx,
			"assets/img/collectible2.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_collectible2)
		ft_printerror("Error loading img_collectible2\n");
	game->img_enemy1 = mlx_xpm_file_to_image(game->mlx,
			"assets/img/enemy1.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_enemy1)
		ft_printerror("Error loading img_enemy1\n");
	game->img_enemy2 = mlx_xpm_file_to_image(game->mlx,
			"assets/img/enemy2.xpm", &game->tile_size, &game->tile_size);
	if (!game->img_enemy2)
		ft_printerror("Error loading img_enemy2\n");
}

void	load_images(t_game *game)
{
	load_floor_images(game);
	load_wall_and_exit_images(game);
	load_player_images(game);
	load_collectible_and_enemy_images(game);
}
