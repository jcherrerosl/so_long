/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:51:24 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/16 08:30:10 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	char **map = malloc((line_count + 1) * sizeof(char *));
	int i = 0;
	char *line;

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
char    **load_map(char *file)
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
    close(fd);
    return (map);
}
