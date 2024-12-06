/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:54:59 by juaherre          #+#    #+#             */
/*   Updated: 2024/12/06 10:35:05 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	start_game(t_game *game, char *file)
{
	game->map = load_map(file, game);
	if (!game->map)
		ft_printerror("Error loading map\n");
	check_map(game->map, file);
	place_enemies(game, game->map);
	game->mlx = mlx_init();
	set_window_size(game);
	game->win = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "so_long");
	if (!find_player(game->map, &game->player_x, &game->player_y))
		ft_printerror("No player found\n");
	game->collectibles = count_collectibles(game->map);
	game->moves = 0;
	game->tile_size = TILE_SIZE;
	game->camera_x = 0;
	game->camera_y = 0;
	game->player_direction = DIRECTION_FRONT;
	load_images(game);
	update_camera(game);
	draw_map(game);
}

void	set_window_size(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	if (window_width > 800)
		window_width = 800;
	if (window_height > 600)
		window_height = 600;
	game->window_width = window_width;
	game->window_height = window_height;
}

void	update_camera(t_game *game)
{
	int	window_width_tiles;
	int	window_height_tiles;

	window_width_tiles = game->window_width / TILE_SIZE;
	window_height_tiles = game->window_height / TILE_SIZE;
	if (game->map_width <= window_width_tiles)
		game->camera_x = (window_width_tiles - game->map_width) / 2;
	else
		game->camera_x = game->player_x - window_width_tiles / 2;
	if (game->map_height <= window_height_tiles)
		game->camera_y = (window_height_tiles - game->map_height) / 2;
	else
		game->camera_y = game->player_y - window_height_tiles / 2;
	if (game->camera_x < 0)
		game->camera_x = 0;
	if (game->camera_y < 0)
		game->camera_y = 0;
	if (game->camera_x > game->map_width - window_width_tiles)
		game->camera_x = game->map_width - window_width_tiles;
	if (game->camera_y > game->map_height - window_height_tiles)
		game->camera_y = game->map_height - window_height_tiles;
}

void	draw_game_status(t_game *game)
{
	char	*collectibles_str;
	char	*moves_str;
	char	*status_str;

	collectibles_str = ft_itoa(game->collectibles);
	moves_str = ft_itoa(game->moves);
	status_str = ft_strjoin("Collectibles remaining: ", collectibles_str);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, status_str);
	free(status_str);
	status_str = ft_strjoin("Moves: ", moves_str);
	mlx_string_put(game->mlx, game->win, 10, 30, 0xFFFFFF, status_str);
	free(status_str);
	free(collectibles_str);
	free(moves_str);
}
