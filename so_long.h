/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:45:03 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/16 19:42:41 by juaherre         ###   ########.fr       */
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
# define KEY_EXIT 17

# define TILE_SIZE 50

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	int		tile_size;

	// images
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_player;
	void	*img_collectible;

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
void		check_map(char **map, char *file);

// check_path.c
char		**duplicate_map(char **map);
void		flood_fill(char **map, int x, int y);
int			check_path(char **map, int start_x, int start_y);
void		free_map(char **map);

// load_map.c
int			count_lines(int fd);
char		**load_lines(int fd, int line_count);
char		**load_map(char *file);

// draw_map.c
void		load_images(t_game *game);
void		draw_tile(t_game *game, char tile, int x, int y);
void		draw_map(t_game *game);

// move_player.c
int			key_handler(int key, t_game *game);

#endif