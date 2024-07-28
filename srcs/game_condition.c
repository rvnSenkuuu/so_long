/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:05:39 by senku             #+#    #+#             */
/*   Updated: 2024/07/28 18:56:01 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_condition(t_game *game, char *game_state)
{
	write(STDERR_FILENO, game_state, ft_strlen(game_state));
	destroy_game(game);
}
