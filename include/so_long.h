/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:39:35 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/20 21:59:25 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/includes/libft.h"
# include "../lib/mlx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

# define ERROR_USAGE "[ERROR]Usage: ./so_long maps/<map.ber>\n"
# define ERROR_WRONG_EXT "[ERROR]Wrong map file extention\n"
# define ERROR_OPEN_FILE "[ERROR]Cannot open file\n"
# define ERROR_READ_FILE "[ERROR]While reading file\n"
# define ERROR_INVALID_MAP "[ERROR]Invalid map\n"

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_img;

typedef	struct s_map
{
	int		height;
	int		width;
	int		count_collectible;
	char	**map;
}				t_map;

typedef	struct s_player
{
	int		x;
	int		y;
	int		step_count;
}				t_player;

typedef struct	s_game
{
	int			game_end;
	void		*mlx;
	void		*mlx_window;
	t_map		*map;
	t_player	*player;
	t_img		*img;
}				t_game;

void	put_error(char *error_str);
void	free_ptrs(void **ptrs);
void	check_argv(int argc, char **argv);
void	get_player_pos(char **map, int *x, int *y);
int		map_is_closed(char **map);
int		map_is_rectangle(char **map);
int		check_valid_char(char **map);
int		check_enough_char(char **map);
int		get_map_height(char *map);
int		check_map_valid(char **map);
char	**read_map(char *file);
t_game	init_game(void);
t_map	*init_map(char *file);
t_map	*set_map_data(char **filled_map);
t_player	*init_player(t_map *map);
t_player	*set_player_data(t_map *game_map);

#endif

/*
	TODO:
	[DONE]-Check si l'extension du fichier est bien un fichier .ber
	-Faire une fonction pour connaitre la taille en largeur de la map en utilisant gnl
	-Relire la map pour l'integrer dans un char ** en utilisant gnl
	-Controle de la map:
		- Si elle est rectangle DONE ??
		- Si c'est une map fermer (les bords doivent etre de 1) DONE ??
		- Check si la map possede un Player, aux moins un Collectible, et un Exit DONE??
		- Check si la map possede uniquement 0 1 E C P DONE ??
		- Faire le pathfinding (FloodFill)
	-Setup la structure du jeu, de la map
*/