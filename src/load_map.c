/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:51:24 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/25 11:28:27 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// #include <stdio.h> // Add for debugging

int	count_lines(int fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	while ((line = get_next_line(fd)))
	{
		line_count++;
		free(line);
	}
	return (line_count);
}

char	**load_lines(int fd, int line_count)
{
	char	**map;
	int		i;
	char	*line;

	map = malloc((line_count + 1) * sizeof(char *));
	i = 0;
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**load_map(char *file, t_game *game)
{
	int		fd;
	char	**map;
	int		line_count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_count = count_lines(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = load_lines(fd, line_count);
	if (!map)
	{
		return (NULL);
	}
	game->map_width = ft_strlen(map[0]) - 1;
	game->map_height = line_count;
	close(fd);
	return (map);
}
