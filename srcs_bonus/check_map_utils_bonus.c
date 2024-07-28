/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:16:44 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/23 10:26:05 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_is_closed(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (FAILURE);
	j = 0;
	while (map[++j])
		if ((map[j][0] != '1') || (map[j][i - 1] != '1'))
			return (FAILURE);
	i = 0;
	while (map[j - 1][i])
	{
		if (map[j - 1][i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	map_is_rectangle(char **map)
{
	int	i;
	int	j;
	int	first_size;

	i = 0;
	first_size = 0;
	while (map[i][first_size])
		first_size++;
	i++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (first_size != j)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	valid_char(char c)
{
	return (c == '0'
		|| c == '1'
		|| c == 'P'
		|| c == 'C'
		|| c == 'E');
}

int	check_valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!valid_char(map[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_enough_char(char **map)
{
	int	i;
	int	j;
	int	player;
	int	collectible;
	int	exit;

	i = -1;
	player = ((collectible = exit = 0));
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'C')
				collectible++;
			else if (map[i][j] == 'E')
				exit++;
		}
	}
	if (player != 1 || exit != 1 || collectible < 1)
		return (FAILURE);
	return (SUCCESS);
}
