/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:08:56 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/29 15:03:40 by tkara2           ###   ########.fr       */
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
	if (game->map->map[x][y] == 'P' && (keycode == XK_w || keycode == XK_W
		|| keycode == XK_Up))
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->imgs->player_u, y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == 'P' && (keycode == XK_s || keycode == XK_S
		|| keycode == XK_Down))
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->imgs->player, y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == 'P' && (keycode == XK_a || keycode == XK_A
		|| keycode == XK_Left))
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->imgs->player_l, y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == 'P' && (keycode == XK_d || keycode == XK_D
		|| keycode == XK_Right))
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->imgs->player_r, y * IMG_SZ, x * IMG_SZ);
}

static void	print_step(t_game *game)
{
	char	*step_count;
	char	*step;

	step = "Step:";
	step_count = ft_itoa(game->map->player->step_count);
	mlx_string_put(game->mlx, game->mlx_window, 20, 31, 0xFFFFFF, step);
	mlx_string_put(game->mlx, game->mlx_window, 28, 41, 0xFFFFFF, step_count);
	free(step_count);
}

static void	print_map(t_game *game, int x, int y, int keycode)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->sign,
			y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == 'B')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->bomb,
			y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->floor,
			y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->wall,
			y * IMG_SZ, x * IMG_SZ);
	else if (game->map->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->imgs->collec,
			y * IMG_SZ, x * IMG_SZ);
	print_player(game, x, y, keycode);
	print_exit(game, x, y);
	print_step(game);
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
