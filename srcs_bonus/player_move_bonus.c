/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:54:03 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 15:21:23 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player_up(t_game *game, t_map *map)
{
	(void)game;
	if (map->map[map->player->x - 1][map->player->y] == 'E'
		&& map->count_collectible != 0)
		return ;
	if (map->map[map->player->x - 1][map->player->y] == '1')
		return ;
	else if (map->map[map->player->x - 1][map->player->y] == 'C')
		map->count_collectible--;
	ft_printf("Conteur de pas: %d\n", map->player->step_count);
	map->player->x--;
	++map->player->step_count;
	map->map[map->player->x][map->player->y] = 'P';
	map->map[map->player->x + 1][map->player->y] = '0';
	if (map->count_collectible == 0
		&& map->map[map->player->x - 1][map->player->y] == 'E')
	{
		++map->player->step_count;
		ft_printf(GAME_WON);
		destroy_game(game);
	}
}

void	move_player_down(t_game *game, t_map *map)
{
	(void)game;
	if (map->map[map->player->x + 1][map->player->y] == 'E'
		&& map->count_collectible != 0)
		return ;
	if (map->map[map->player->x + 1][map->player->y] == '1')
		return ;
	else if (map->map[map->player->x + 1][map->player->y] == 'C')
		map->count_collectible--;
	ft_printf("Conteur de pas: %d\n", map->player->step_count);
	map->player->x++;
	++map->player->step_count;
	map->map[map->player->x][map->player->y] = 'P';
	map->map[map->player->x - 1][map->player->y] = '0';
	if (map->count_collectible == 0
		&& map->map[map->player->x + 1][map->player->y] == 'E')
	{
		++map->player->step_count;
		ft_printf(GAME_WON);
		destroy_game(game);
	}
}

void	move_player_right(t_game *game, t_map *map)
{
	(void)game;
	if (map->map[map->player->x][map->player->y + 1] == 'E'
		&& map->count_collectible != 0)
		return ;
	if (map->map[map->player->x][map->player->y + 1] == '1')
		return ;
	else if (map->map[map->player->x][map->player->y + 1] == 'C')
		map->count_collectible--;
	ft_printf("Conteur de pas: %d\n", map->player->step_count);
	map->player->y++;
	++map->player->step_count;
	map->map[map->player->x][map->player->y] = 'P';
	map->map[map->player->x][map->player->y - 1] = '0';
	if (map->count_collectible == 0
		&& map->map[map->player->x][map->player->y + 1] == 'E')
	{
		++map->player->step_count;
		ft_printf(GAME_WON);
		destroy_game(game);
	}
}

void	move_player_left(t_game *game, t_map *map)
{
	(void)game;
	if (map->map[map->player->x][map->player->y - 1] == 'E'
		&& map->count_collectible != 0)
		return ;
	if (map->map[map->player->x][map->player->y - 1] == '1')
		return ;
	else if (map->map[map->player->x][map->player->y - 1] == 'C')
		map->count_collectible--;
	ft_printf("Counteur de pas: %d\n", map->player->step_count);
	map->player->y--;
	++map->player->step_count;
	map->map[map->player->x][map->player->y] = 'P';
	map->map[map->player->x][map->player->y + 1] = '0';
	if (map->count_collectible == 0
		&& map->map[map->player->x][map->player->y - 1] == 'E')
	{
		++map->player->step_count;
		ft_printf(GAME_WON);
		destroy_game(game);
	}
}
