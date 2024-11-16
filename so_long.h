/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:45:03 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/16 03:10:15 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

// voy a usar las flechas del teclado para mover el personaje
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
}			t_game;

// count_elements.c
int			count_players(char **map);
int			count_collectibles(char **map);
int			count_exits(char **map);
int			find_player(char **map, int *x, int *y);

// check_map.c
int			check_extension(char *file);
int			check_rectangular(char **map);
int			check_walls(char **map);
int			check_elements(char **map);
void 		check_map(char **map, char *file);

// check_path.c
char		**duplicate_map(char **map);
void		flood_fill(char **map, int x, int y);
int			check_path(char **map, int start_x, int start_y);
void		free_map(char **map);

// load_map.c
int		count_lines(int fd);
char	**load_lines(int fd, int line_count);
char	**load_map(char *file);


#endif