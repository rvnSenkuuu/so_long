/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:37:14 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/20 22:00:18 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	init_game(void)
{
	t_game	game;

	game.mlx = NULL;
	game.mlx_window = NULL;
	game.player = NULL;
	game.map = NULL;
	game.img = NULL;
	game.game_end = 0;
	return (game);
}

t_map	*init_map(char *file)
{
	char	**filled_map;
	t_map	*map;

	filled_map = read_map(file);
	check_map_valid(filled_map);
	map = set_map_data(filled_map);
	return (map);
}

t_player	*init_player(t_map *game_map)
{
	t_player	*player;

	player = set_player_data(game_map);	
	return (player);
}