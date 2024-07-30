/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:40:21 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/29 18:50:46 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_error_exit(char *error_str)
{
	write(STDERR_FILENO, error_str, ft_strlen(error_str));
	exit(FAILURE);
}

void	free_error_exit(t_game *game, char *error_str)
{
	write(STDERR_FILENO, error_str, ft_strlen(error_str));
	destroy_game(game);
	exit(FAILURE);
}

void	free_ptrs_exit(char **map)
{
	free_ptrs((void **)map);
	exit(FAILURE);
}

void	error_close_exit(char *error_str, int fd)
{
	write(STDERR_FILENO, error_str, ft_strlen(error_str));
	close(fd);
	exit(FAILURE);
}
