/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:25:35 by juaherre          #+#    #+#             */
/*   Updated: 2024/12/06 11:41:30 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**duplicate_map(char **map)
{
	int		i;
	char	**dup;

	i = 0;
	while (map[i])
		i++;
	dup = malloc((i + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'X')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_path(char **map, int start_x, int start_y)
{
	char	**dup;
	int		y;
	int		x;

	dup = duplicate_map(map);
	if (!dup)
		return (0);
	flood_fill(dup, start_x, start_y);
	y = 0;
	while (dup[y])
	{
		x = 0;
		while (dup[y][x])
		{
			if (dup[y][x] == 'C' || dup[y][x] == 'E')
			{
				free_map(dup);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_map(dup);
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
