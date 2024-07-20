/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:48:36 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/20 22:02:47 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_collectible(char **map)
{
	int	height;
	int	width;
	int	collectible;

	height = 0;
	width = 0;
	collectible = 0;
	while (map[height])
	{
		while (map[height][width])
		{
			if (map[height][width] == 'C')
				collectible++;
			width++;
		}
		height++;
	}
	return (collectible);
}

void	get_player_pos(char **map, int *x, int *y)
{
	int	height;
	int	width;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] == 'P')
			{
				*x = height;
				*y = width;
			}
			width++;
		}
		height++;
	}
}

t_map	*set_map_data(char **filled_map)
{
	int		height;
	t_map	*game_map;

	height = 0;
	while (filled_map[height])
		height++;
	game_map = malloc(sizeof(t_map));
	if (!game_map)
		free_ptrs((void **)filled_map);
	game_map->map = filled_map;
	game_map->count_collectible = get_map_collectible(filled_map);
	game_map->height = height;
	game_map->width = ft_strlen(filled_map[0]);
	return (game_map);
}

t_player	*set_player_data(t_map *game_map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->step_count = 0;
	get_player_pos(game_map->map, &player->x, &player->y);
	return (player);
}