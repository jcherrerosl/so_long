/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:51:10 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/16 03:03:22 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    char **map;

    if (argc != 2)
    {
        ft_putendl_fd("Usage: ./so_long <map_file>", 2);
        return (1);
    }
    map = load_map(argv[1]);
    if (!map)
        ft_printerror("Error\nFailed to load map");
    check_map(map, argv[1]);
    ft_putendl_fd("Map is valid!", 1);
    free_map(map);
    return (0);
}
