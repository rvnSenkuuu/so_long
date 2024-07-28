/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:39:35 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 15:22:28 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/includes/libft.h"
# include "../lib/mlx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SUCCESS 0
# define FAILURE 1
# define GAME_NAME "SO_LONG"
# define IMG_SZ 64
# define GAME_WON "You finished the game. Congratulation\n"

# define FLOOR	"./assets/floor.xpm"
# define WALL	"./assets/wall.xpm"
# define COLLEC	"./assets/collec.xpm"
# define PLAYER	"./assets/player.xpm"
# define PLAYER_U	"./assets/player_up.xpm"
# define PLAYER_L	"./assets/player_left.xpm"
# define PLAYER_R	"./assets/player_right.xpm"
# define EXIT_C	"./assets/exit_unreachable.xpm"
# define EXIT_O	"./assets/exit_reachable.xpm"

# define E_USAGE "Error\nUsage: ./so_long maps/<map.ber>\n"
# define E_WRONG_EXT "Error\nWrong map file extention\n"
# define E_OPEN_FILE "Error\nCannot open file\n"
# define E_READ_FILE "Error\nWhile reading file\n"
# define E_INVALID_CHAR "Error\nInvalid char in map\n"
# define E_MAP_NOT_CLOSE "Error\nMap is not closed\n"
# define E_MAP_CHAR_NBR "Error\nMap contains more than 1 player or exit\n"
# define E_MAP_NOT_RECTANGLE "Error\nInvalid map is not rectangular\n"
# define E_MAP_PATH "Error\nNo path found to exit or collectibles\n"
# define E_ALLOC "Error\nAllocation failed\n"
# define E_INIT_IMG "Error\nWhile creating images\n"

typedef struct s_img
{
	int		width;
	int		height;
	void	*floor;
	void	*wall;
	void	*player;
	void	*player_u;
	void	*player_l;
	void	*player_r;
	void	*collec;
	void	*exit_c;
	void	*exit_o;
}				t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		step_count;
}				t_player;

typedef struct s_map
{
	int			height;
	int			width;
	int			count_collectible;
	int			collec_ff;
	char		**map;
	char		**copy;
	t_player	*player;
}				t_map;

typedef struct s_game
{
	int			game_end;
	void		*mlx;
	void		*mlx_window;
	t_map		*map;
	t_img		*imgs;
}				t_game;

//Utils
void	put_error_exit(char *error_str);
void	free_ptrs(void **ptrs);
void	free_error_exit(t_game *game, char *error_str);
int		destroy_game(t_game *game);
void	destroy_img(t_game *game);
void	check_argv(int argc, char **argv);
void	get_player_pos(char **map, int *x, int *y);
void	display_map(t_map *map);

//File reading functions
char	**read_map(char *file);
int		get_map_height(char *map);

//Check if map is valid map functions
void	check_map(char **map);
int		map_is_closed(char **map);
int		map_is_rectangle(char **map);
int		check_valid_char(char **map);
int		check_enough_char(char **map);
void	check_map_path(t_map *map);

//Structure initialization
t_map	*init_map(char *file);
t_map	*set_map_data(char **map);

//Handle mlx
void	init_mlx(t_game *game);
int		key_hook(int keycode, t_game *game);
int		render_map(t_game *game);

//Handle move player
void	move_player_up(t_game *game, t_map *map);
void	move_player_down(t_game *game, t_map *map);
void	move_player_right(t_game *game, t_map *map);
void	move_player_left(t_game *game, t_map *map);

#endif