/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:48:36 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 15:21:33 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_map_collectible(char **map)
{
	int	i;
	int	j;
	int	collectible;

	i = 0;
	collectible = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
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

char	**copy_map(char **map)
{
	int		i;
	int		height;
	char	**copy;

	i = 0;
	height = 0;
	while (map[height])
		height++;
	copy = ft_calloc(height + 1, sizeof(char *));
	if (!copy)
		free_ptrs((void **)map);
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}

t_map	*set_map_data(char **map)
{
	int			height;
	t_map		*game_map;
	t_player	*p;

	height = 0;
	while (map[height])
		height++;
	game_map = ft_calloc(1, sizeof(t_map));
	if (!game_map)
		free_ptrs((void **)map);
	p = ft_calloc(1, sizeof(t_player));
	if (!p)
		free_ptrs((void **)map);
	game_map->player = p;
	game_map->map = map;
	game_map->copy = copy_map(map);
	game_map->count_collectible = get_map_collectible(map);
	game_map->height = height;
	game_map->width = ft_strlen(map[0]);
	get_player_pos(map, &game_map->player->x, &game_map->player->y);
	return (game_map);
}
