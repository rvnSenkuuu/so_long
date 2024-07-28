/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:05:18 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/28 15:20:58 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		move_player_up(game, game->map);
	if (keycode == XK_s || keycode == XK_S)
		move_player_down(game, game->map);
	if (keycode == XK_d || keycode == XK_D)
		move_player_right(game, game->map);
	if (keycode == XK_a || keycode == XK_A)
		move_player_left(game, game->map);
	if (keycode == XK_Escape)
		destroy_game(game);
	render_map(game);
	return (SUCCESS);
}

int	init_imgs(t_game *game)
{
	game->imgs = ft_calloc(1, sizeof(t_img));
	if (!game->imgs)
		return (FAILURE);
	game->imgs->floor = mlx_xpm_file_to_image(game->mlx, FLOOR,
			&game->imgs->width, &game->imgs->height);
	if (!game->imgs->floor)
		put_error_exit(E_INIT_IMG);
	game->imgs->wall = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->imgs->width, &game->imgs->height);
	if (!game->imgs->wall)
		free_error_exit(game, E_INIT_IMG);
	game->imgs->collec = mlx_xpm_file_to_image(game->mlx, COLLEC,
			&game->imgs->width, &game->imgs->height);
	if (!game->imgs->collec)
		free_error_exit(game, E_INIT_IMG);
	game->imgs->player = mlx_xpm_file_to_image(game->mlx, PLAYER,
			&game->imgs->width, &game->imgs->height);
	if (!game->imgs->player)
		free_error_exit(game, E_INIT_IMG);
	game->imgs->exit_o = mlx_xpm_file_to_image(game->mlx, EXIT_O,
			&game->imgs->width, &game->imgs->height);
	if (!game->imgs->exit_o)
		free_error_exit(game, E_INIT_IMG);
	return (SUCCESS);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		destroy_game(game);
	game->mlx_window = mlx_new_window(game->mlx, game->map->width * IMG_SZ,
			game->map->height * IMG_SZ, GAME_NAME);
	if (!game->mlx_window)
		destroy_game(game);
	if (init_imgs(game) == FAILURE)
		destroy_img(game);
	render_map(game);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, DestroyNotify, StructureNotifyMask,
		destroy_game, game);
	mlx_loop(game->mlx);
}
