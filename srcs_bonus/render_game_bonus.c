/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:08:56 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 16:43:42 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_exit(t_game *game, int x, int y)
{
	if (game->map->map[x][y] == 'E' && game->map->count_collectible == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->exit_o,
			y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->exit_c,
			y * IMG_SZ, x * IMG_SZ);
}

void	print_map(t_game *game, int x, int y)
{
	if (game->map->map[x][y] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->floor,
			y * IMG_SZ, x * IMG_SZ);
	if (game->map->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->wall,
			y * IMG_SZ, x * IMG_SZ);
	if (game->map->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->collec,
			y * IMG_SZ, x * IMG_SZ);
	if (game->map->map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->player,
			y * IMG_SZ, x * IMG_SZ);
	print_exit(game, x, y);
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i] && i < game->map->height)
	{
		j = 0;
		while (game->map->map[i][j] && j < game->map->width)
		{
			print_map(game, i, j);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
