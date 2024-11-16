/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:51:10 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/16 19:47:31 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    
    if (argc != 2)
        ft_printerror("Usage: ./so_long map.ber\n");
    game.map = load_map(argv[1]);
    if (!game.map)
        ft_printerror("Error loading map\n");
    check_map(game.map, argv[1]);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 800, 600, "so_long");
    if (!find_player(game.map, &game.player_x, &game.player_y))
        ft_printerror("No player found\n");
    game.collectibles = count_collectibles(game.map);
    game.moves = 0;
    game.tile_size = TILE_SIZE;
    load_images(&game);
    draw_map(&game);
    mlx_key_hook(game.win, key_handler, &game);
    mlx_loop(game.mlx);
    return (0);
}
