/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:32:43 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/29 14:52:00 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_ptrs(void **ptrs)
{
	size_t	i;

	if (!ptrs)
		return ;
	i = 0;
	while (ptrs[i])
	{
		free(ptrs[i]);
		i++;
	}
	free(ptrs);
	ptrs = NULL;
}

void	destroy_img(t_game *game)
{
	if (game->imgs->floor)
		mlx_destroy_image(game->mlx, game->imgs->floor);
	if (game->imgs->wall)
		mlx_destroy_image(game->mlx, game->imgs->wall);
	if (game->imgs->collec)
		mlx_destroy_image(game->mlx, game->imgs->collec);
	if (game->imgs->player)
		mlx_destroy_image(game->mlx, game->imgs->player);
	if (game->imgs->player_u)
		mlx_destroy_image(game->mlx, game->imgs->player_u);
	if (game->imgs->player_l)
		mlx_destroy_image(game->mlx, game->imgs->player_l);
	if (game->imgs->player_r)
		mlx_destroy_image(game->mlx, game->imgs->player_r);
	if (game->imgs->exit_c)
		mlx_destroy_image(game->mlx, game->imgs->exit_c);
	if (game->imgs->exit_o)
		mlx_destroy_image(game->mlx, game->imgs->exit_o);
	if (game->imgs->sign)
		mlx_destroy_image(game->mlx, game->imgs->sign);
	if (game->imgs->bomb)
		mlx_destroy_image(game->mlx, game->imgs->bomb);
	free(game->imgs);
}

void	destroy_map(t_map *map)
{
	free_ptrs((void **)map->map);
	free_ptrs((void **)map->copy);
	free(map->player);
	free(map);
}

int	destroy_game(t_game *game)
{
	if (game->map)
		destroy_map(game->map);
	if (game->mlx)
	{
		if (game->imgs)
			destroy_img(game);
		mlx_loop_end(game->mlx);
		if (game->mlx_window)
			mlx_destroy_window(game->mlx, game->mlx_window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(SUCCESS);
}
