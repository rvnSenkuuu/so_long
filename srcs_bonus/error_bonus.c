/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:40:21 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 15:08:39 by senku            ###   ########.fr       */
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
