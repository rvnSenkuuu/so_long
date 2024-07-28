/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:24:22 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 15:19:25 by senku            ###   ########.fr       */
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
