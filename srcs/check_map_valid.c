/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:24:22 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/19 17:32:46 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_valid(char **map)
{
	if (!map_is_closed(map))
	{
		free_ptrs((void **)map);
		put_error(ERROR_INVALID_MAP);
	}
	if (!map_is_rectangle(map))
	{
		free_ptrs((void **)map);
		put_error(ERROR_INVALID_MAP);
	}
	if (!check_valid_char(map))
	{
		free_ptrs((void **)map);
		put_error(ERROR_INVALID_MAP);
	}
	if (!check_enough_char(map))
	{
		free_ptrs((void **)map);
		put_error(ERROR_INVALID_MAP);
	}
	return (EXIT_SUCCESS);
}
