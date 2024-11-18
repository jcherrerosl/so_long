/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:46:40 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/18 12:26:05 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_conditions(t_game *game)
{
	if (game->collectibles == 0
		&& game->map[game->player_y][game->player_x] == 'E')
	{
		ft_printf("You won!🥳🥳\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
}

void	move_player(t_game *game, int *on_exit, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectibles--;
		if (*on_exit == 0)
			game->map[game->player_y][game->player_x] = '0';
		else
			game->map[game->player_y][game->player_x] = 'E';
		game->player_x = new_x;
		game->player_y = new_y;
		if (game->map[game->player_y][game->player_x] == 'E')
			*on_exit = 1;
		else
			*on_exit = 0;
		check_exit_conditions(game);
		game->map[game->player_y][game->player_x] = 'P';
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		update_camera(game);
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
		draw_game_status(game);
	}
}

int	key_handler(int key, t_game *game)
{
	static int	on_exit = 0;

	if (key == KEY_UP || key == KEY_W)
	{
		game->player_direction = DIRECTION_BACK;
		move_player(game, &on_exit, game->player_x, game->player_y - 1);
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		game->player_direction = DIRECTION_FRONT;
		move_player(game, &on_exit, game->player_x, game->player_y + 1);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		game->player_direction = DIRECTION_LEFT;
		move_player(game, &on_exit, game->player_x - 1, game->player_y);
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		game->player_direction = DIRECTION_RIGHT;
		move_player(game, &on_exit, game->player_x + 1, game->player_y);
	}
	if (key == KEY_ESC)
	{
		ft_printf("Exiting game\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}
