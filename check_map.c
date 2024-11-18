/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:05:59 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/18 14:13:12 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *file)
{
	if (ft_strlen(file) < 4 || ft_strncmp(file + ft_strlen(file) - 4, ".ber",
			4) != 0)
		return (0);
	return (1);
}

int	check_rectangular(char **map)
{
	int	i;
	int	len;
	int	row_len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	if (map[0][len - 1] == '\n')
		len--;
	i = 1;
	while (map[i])
	{
		row_len = ft_strlen(map[i]);
		if (map[i][row_len - 1] == '\n')
			row_len--;
		if (row_len != len)
			return (0);
		i++;
	}
	return (1);
}

void	trim_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}

int	check_walls(char **map)
{
	int	i;
	int	len;
	int	rows;

	rows = ft_countrows(map);
	trim_newline(map[0]);
	trim_newline(map[rows - 1]);
	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[0][i] && map[rows - 1][i])
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_elements(char **map)
{
	int	players;
	int	collectibles;
	int	exits;

	players = count_players(map);
	collectibles = count_collectibles(map);
	exits = count_exits(map);
	if (players != 1 || collectibles < 1 || exits != 1)
	{
		return (0);
	}
	return (1);
}

void	check_map(char **map, char *file)
{
	int	player_x;
	int	player_y;

	if (!check_extension(file))
		ft_printerror("Invalid file extension");
	if (!check_rectangular(map))
		ft_printerror("Map is not rectangular");
	if (!check_walls(map))
		ft_printerror("Map is not surrounded by walls");
	if (!check_elements(map))
		ft_printerror("Invalid map elements");
	if (!find_player(map, &player_x, &player_y))
		ft_printerror("Player not found");
	if (!check_path(map, player_x, player_y))
		ft_printerror("Map is not playable");
}
