/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.ft>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:08:56 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 19:19:27 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	print_exit(t_game *game, int x, int y)
{
	if (game->map->map[x][y] == 'E' && game->map->count_collectible == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->exit_o,
			y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->exit_c,
			y * IMG_SZ, x * IMG_SZ);
}

static void	print_player(t_game *game, int x, int y, int keycode)
{
	if (game->map->map[x][y] == 'P' && keycode == XK_w)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->imgs->player_u, y * IMG_SZ, x * IMG_SZ);
	if (game->map->map[x][y] == 'P' && keycode == XK_s)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->imgs->player, y * IMG_SZ, x * IMG_SZ);
	if (game->map->map[x][y] == 'P' && keycode == XK_d)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->imgs->player_r, y * IMG_SZ, x * IMG_SZ);
	if (game->map->map[x][y] == 'P' && keycode == XK_a)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->imgs->player_l, y * IMG_SZ, x * IMG_SZ);
}

void	print_map(t_game *game, int x, int y, int keycode)
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
	print_player(game, x, y, keycode);
	print_exit(game, x, y);
}

int	render_map_bonus(t_game *game, int keycode)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i] && i < game->map->height)
	{
		j = 0;
		while (game->map->map[i][j] && j < game->map->width)
		{
			print_map(game, i, j, keycode);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
