/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:39:35 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/29 18:56:11 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/includes/libft.h"
# include "../lib/mlx-linux/mlx.h"
# include "so_long_define.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

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
	void	*sign;
	void	*bomb;
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
	int			scr_w;
	int			scr_h;
	void		*mlx;
	void		*mlx_window;
	t_map		*map;
	t_img		*imgs;
}				t_game;

//Utils
void	put_error_exit(char *error_str);
void	error_close_exit(char *error_str, int fd);
void	free_ptrs(void **ptrs);
void	free_error_exit(t_game *game, char *error_str);
void	free_ptrs_exit(char **map);
int		destroy_game(t_game *game);
void	destroy_map(t_map *map);
void	destroy_img(t_game *game);
void	check_argv(int argc, char **argv);
void	get_player_pos(char **map, int *x, int *y);

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
int		init_imgs(t_game *game);
int		key_hook(int keycode, t_game *game);
int		render_map(t_game *game);
int		render_map_bonus(t_game *game, int keycode);

//Handle move player
void	move_player_up(t_game *game, t_map *map);
void	move_player_down(t_game *game, t_map *map);
void	move_player_right(t_game *game, t_map *map);
void	move_player_left(t_game *game, t_map *map);

//Game condition
void	game_condition(t_game *game, char *game_state);

#endif