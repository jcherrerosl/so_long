/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:46:40 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/16 19:42:09 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_x;
	pos_y = game->player_y - 1;
	if (game->map[pos_y][pos_x] != '1')
	{
		if (game->map[pos_y][pos_x] == 'C')
			game->collectibles--;
		game->map[game->player_y][game->player_x] = '0';
		game->player_y = pos_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
	}
}
void	move_down(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_x;
	pos_y = game->player_y + 1;
	if (game->map[pos_y][pos_x] != '1')
	{
		if (game->map[pos_y][pos_x] == 'C')
			game->collectibles--;
		game->map[game->player_y][game->player_x] = '0';
		game->player_y = pos_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
	}
}

void	move_left(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_x - 1;
	pos_y = game->player_y;
	if (game->map[pos_y][pos_x] != '1')
	{
		if (game->map[pos_y][pos_x] == 'C')
			game->collectibles--;
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = pos_x;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
	}
}

void	move_right(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_x + 1;
	pos_y = game->player_y;
	if (game->map[pos_y][pos_x] != '1')
	{
		if (game->map[pos_y][pos_x] == 'C')
			game->collectibles--;
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = pos_x;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
	}
}
int	key_handler(int key, t_game *game)
{
	if (key == KEY_UP)
		move_up(game);
	else if (key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_LEFT)
		move_left(game);
	else if (key == KEY_RIGHT)
		move_right(game);
	if (key == KEY_ESC || key == KEY_EXIT)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}
