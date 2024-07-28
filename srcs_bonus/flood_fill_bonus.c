/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:48:21 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 15:21:56 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	fill(t_map *map, char **copy, int pos_x, int pos_y)
{
	if (pos_x <= 0 || pos_y <= 0 || pos_x >= map->height
		|| pos_x >= map->width)
		return (FAILURE);
	if (copy[pos_x][pos_y] == 'F' || (copy[pos_x][pos_y] != '0'
		&& copy[pos_x][pos_y] != 'C' && copy[pos_x][pos_y] != 'P'
		&& copy[pos_x][pos_y] != 'E'))
		return (FAILURE);
	if (copy[pos_x][pos_y] == 'C')
		map->collec_ff--;
	if (copy[pos_x][pos_y] == 'E')
	{
		copy[pos_x][pos_y] = 'F';
		if (map->collec_ff != 0)
			return (FAILURE);
	}
	copy[pos_x][pos_y] = 'F';
	fill(map, copy, pos_x - 1, pos_y);
	fill(map, copy, pos_x + 1, pos_y);
	fill(map, copy, pos_x, pos_y - 1);
	fill(map, copy, pos_x, pos_y + 1);
	return (FAILURE);
}

static void	flood_fill(t_map *map, char **copy, int pos_x, int pos_y)
{
	map->collec_ff = map->count_collectible;
	if (fill(map, copy, pos_x, pos_y) != 1)
		put_error_exit(E_MAP_PATH);
}

static int	check_after_ff(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->copy[i])
	{
		j = 0;
		while (map->copy[i][j])
		{
			if (map->copy[i][j] == 'C' || map->copy[i][j] == 'P'
				|| map->copy[i][j] == 'E')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

void	check_map_path(t_map *map)
{
	flood_fill(map, map->copy, map->player->x, map->player->y);
	if (check_after_ff(map) == 1)
		put_error_exit(E_MAP_PATH);
}
