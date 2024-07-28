/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_condition_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:05:39 by senku             #+#    #+#             */
/*   Updated: 2024/07/28 18:07:49 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_win(t_game *game)
{
	ft_printf(GAME_WON);
	destroy_game(game);
}

void	game_lose(t_game *game)
{
	ft_printf(GAME_LOSE);
	destroy_game(game);
}
