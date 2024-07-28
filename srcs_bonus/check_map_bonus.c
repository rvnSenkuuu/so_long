/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.ft>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:24:22 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 18:59:56 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(char **map)
{
	if (map_is_closed(map) != SUCCESS)
	{
		free_ptrs((void **)map);
		put_error_exit(E_MAP_NOT_CLOSE);
	}
	else if (map_is_rectangle(map) != SUCCESS)
	{
		free_ptrs((void **)map);
		put_error_exit(E_MAP_NOT_RECTANGLE);
	}
	else if (check_valid_char(map) != SUCCESS)
	{
		free_ptrs((void **)map);
		put_error_exit(E_INVALID_CHAR);
	}
	else if (check_enough_char(map) != SUCCESS)
	{
		free_ptrs((void **)map);
		put_error_exit(E_MAP_CHAR_NBR);
	}
}
