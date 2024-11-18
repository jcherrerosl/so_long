/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:21:35 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/18 12:35:03 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game, char tile, int x, int y)
{
	int	draw_x;
	int	draw_y;

	draw_x = (x - game->camera_x) * TILE_SIZE;
	draw_y = (y - game->camera_y) * TILE_SIZE;
	if (game->player_direction == DIRECTION_FRONT)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_front,
			draw_x, draw_y);
	else if (game->player_direction == DIRECTION_BACK)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_back,
			draw_x, draw_y);
	else if (game->player_direction == DIRECTION_LEFT)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_left,
			draw_x, draw_y);
	else if (game->player_direction == DIRECTION_RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_right,
			draw_x, draw_y);
}

void	draw_collectibles(t_game *game, char tile, int x, int y)
{
	int	draw_x;
	int	draw_y;

	draw_x = (x - game->camera_x) * TILE_SIZE;
	draw_y = (y - game->camera_y) * TILE_SIZE;
	if (tile == 'C')
	{
		if (game->moves % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
				draw_x, draw_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_collectible2,
				draw_x, draw_y);
	}
}

void	draw_exit(t_game *game, char tile, int x, int y)
{
	int	draw_x;
	int	draw_y;

	draw_x = (x - game->camera_x) * TILE_SIZE;
	draw_y = (y - game->camera_y) * TILE_SIZE;
	if (tile == 'E')
	{
		if (game->collectibles == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open,
				draw_x, draw_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit_closed,
				draw_x, draw_y);
	}
}

void	draw_tile(t_game *game, char tile, int x, int y)
{
	int	draw_x;
	int	draw_y;

	draw_x = (x - game->camera_x) * TILE_SIZE;
	draw_y = (y - game->camera_y) * TILE_SIZE;
	if (draw_x >= 0 && draw_x < game->window_width && draw_y >= 0
		&& draw_y < game->window_height)
	{
		if (tile == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
				draw_x, draw_y);
		else if (tile == '0' && game->moves % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor1,
				draw_x, draw_y);
		else if (tile == '0' && game->moves % 2 != 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor2,
				draw_x, draw_y);
		else if (tile == 'P')
			draw_player(game, tile, x, y);
		else if (tile == 'E')
			draw_exit(game, tile, x, y);
		else if (tile == 'C')
			draw_collectibles(game, tile, x, y);
	}
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
	draw_game_status(game);
}
