/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaherre <juaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:45:03 by juaherre          #+#    #+#             */
/*   Updated: 2024/11/18 14:06:33 by juaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ESC 65307

# define TILE_SIZE 32

# define DIRECTION_FRONT 0
# define DIRECTION_BACK 1
# define DIRECTION_LEFT 2
# define DIRECTION_RIGHT 3

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
	void	*img_floor1;
	void	*img_floor2;
	void	*img_exit_open;
	void	*img_exit_closed;
	void	*img_player_front;
	void	*img_player_back;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_collectible;
	void	*img_collectible2;

	int		camera_x;
	int		camera_y;
	int		window_width;
	int		window_height;
	int		map_width;
	int		map_height;

	int		player_direction;

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
char		**load_map(char *file, t_game *game);

// draw_map.c
void		draw_tile(t_game *game, char tile, int x, int y);
void		draw_exit(t_game *game, char tile, int x, int y);
void		draw_collectibles(t_game *game, char tile, int x, int y);
void		draw_player(t_game *game, char tile, int x, int y);
void		draw_map(t_game *game);

// move_player.c
void		move_player(t_game *game, int *on_exit, int new_x, int new_y);
int			key_handler(int key, t_game *game);

// start_game.c
void		start_game(t_game *game, char *file);
void		set_window_size(t_game *game);
void		draw_game_status(t_game *game);
void		update_camera(t_game *game);

// load_images.c
void		load_images(t_game *game);

int			close_window(t_game *game);

#endif