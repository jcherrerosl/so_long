/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:51:10 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/25 11:28:57 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game *game)
{
	ft_printf("Exiting game\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_printerror("Usage: ./so_long <map.ber>\n");
	start_game(&game, argv[1]);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
