/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:37:14 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/24 18:05:48 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*init_map(char *file)
{
	char	**map;
	t_map	*game_map;

	map = read_map(file);
	check_map(map);
	game_map = set_map_data(map);
	check_map_path(game_map);
	return (game_map);
}
