/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.ft>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:04 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 19:00:12 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_height(char *map)
{
	int		height;
	int		fd;
	char	buffer;

	height = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		put_error_exit(E_OPEN_FILE);
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
			height++;
	}
	close(fd);
	return (height + 1);
}

char	**read_map(char *file)
{
	int		map_height;
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	map_height = get_map_height(file);
	map = ft_calloc(map_height + 1, sizeof(char *));
	if (!map)
		return (NULL);
	while (i < map_height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
