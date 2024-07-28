/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.ft>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:05:18 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 19:16:02 by tkara2           ###   ########.fr       */
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

static void	check_imgs(t_game *game)
{
	if (!game->imgs->floor)
		put_error_exit(E_INIT_F_IMG);
	if (!game->imgs->wall)
		free_error_exit(game, E_INIT_W_IMG);
	if (!game->imgs->collec)
		free_error_exit(game, E_INIT_C_IMG);
	if (!game->imgs->player)
		free_error_exit(game, E_INIT_P_IMG);
	if (!game->imgs->player_l)
		free_error_exit(game, E_INIT_PL_IMG);
	if (!game->imgs->player_r)
		free_error_exit(game, E_INIT_PR_IMG);
	if (!game->imgs->player_u)
		free_error_exit(game, E_INIT_PU_IMG);
	if (!game->imgs->exit_o)
		free_error_exit(game, E_INIT_EO_IMG);
	if (!game->imgs->exit_c)
		free_error_exit(game, E_INIT_EC_IMG);
}

int	init_imgs(t_game *game)
{
	game->imgs = ft_calloc(1, sizeof(t_img));
	if (!game->imgs)
		return (FAILURE);
	game->imgs->floor = mlx_xpm_file_to_image(game->mlx, FLOOR,
			&game->imgs->width, &game->imgs->height);
	game->imgs->wall = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->imgs->width, &game->imgs->height);
	game->imgs->collec = mlx_xpm_file_to_image(game->mlx, COLLEC,
			&game->imgs->width, &game->imgs->height);
	game->imgs->player = mlx_xpm_file_to_image(game->mlx, PLAYER,
			&game->imgs->width, &game->imgs->height);
	game->imgs->player_u = mlx_xpm_file_to_image(game->mlx, PLAYER_U,
			&game->imgs->width, &game->imgs->height);
	game->imgs->player_l = mlx_xpm_file_to_image(game->mlx, PLAYER_L,
			&game->imgs->width, &game->imgs->height);
	game->imgs->player_r = mlx_xpm_file_to_image(game->mlx, PLAYER_R,
			&game->imgs->width, &game->imgs->height);
	game->imgs->exit_o = mlx_xpm_file_to_image(game->mlx, EXIT_O,
			&game->imgs->width, &game->imgs->height);
	game->imgs->exit_c = mlx_xpm_file_to_image(game->mlx, EXIT_C,
			&game->imgs->width, &game->imgs->height);
	check_imgs(game);
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
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, DestroyNotify, StructureNotifyMask,
		destroy_game, game);
	mlx_loop(game->mlx);
}
