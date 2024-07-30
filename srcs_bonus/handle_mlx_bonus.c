/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:05:18 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/29 11:53:51 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		move_player_up(game, game->map);
	if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		move_player_down(game, game->map);
	if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		move_player_right(game, game->map);
	if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		move_player_left(game, game->map);
	if (keycode == XK_Escape)
		game_condition(game, GAME_QUIT);
	render_map_bonus(game, keycode);
	return (SUCCESS);
}

static void	check_screen_size(t_game *game)
{
	game->scr_w = SCR_W;
	game->scr_h = SCR_H;
	if (game->scr_w < (game->map->width * IMG_SZ))
		free_error_exit(game, E_MAP_WSZ);
	if (game->scr_h < (game->map->height * IMG_SZ))
		free_error_exit(game, E_MAP_HSZ);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free_error_exit(game, E_MLX);
	check_screen_size(game);
	game->mlx_window = mlx_new_window(game->mlx, game->map->width * IMG_SZ,
			game->map->height * IMG_SZ, GAME_NAME);
	if (!game->mlx_window)
		free_error_exit(game, E_MLX_WIN);
	if (init_imgs(game) == FAILURE)
		destroy_img(game);
	render_map_bonus(game, XK_s);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, DestroyNotify, StructureNotifyMask,
		destroy_game, game);
	mlx_loop(game->mlx);
}
