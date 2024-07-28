/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_condition_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.ft>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:05:39 by senku             #+#    #+#             */
/*   Updated: 2024/07/28 19:00:04 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_condition(t_game *game, char *game_state)
{
	write(STDERR_FILENO, game_state, ft_strlen(game_state));
	destroy_game(game);
}
