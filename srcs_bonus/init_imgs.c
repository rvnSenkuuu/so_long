/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:52:56 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/29 13:42:31 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	if (!game->imgs->sign)
		free_error_exit(game, E_INIT_S_IMG);
	if (!game->imgs->bomb)
		free_error_exit(game, E_INIT_B_IMG);
}

static void	init_player(t_game *game)
{
	game->imgs->player = mlx_xpm_file_to_image(game->mlx, PLAYER,
			&game->imgs->width, &game->imgs->height);
	game->imgs->player_u = mlx_xpm_file_to_image(game->mlx, PLAYER_U,
			&game->imgs->width, &game->imgs->height);
	game->imgs->player_l = mlx_xpm_file_to_image(game->mlx, PLAYER_L,
			&game->imgs->width, &game->imgs->height);
	game->imgs->player_r = mlx_xpm_file_to_image(game->mlx, PLAYER_R,
			&game->imgs->width, &game->imgs->height);
}

static void	init_exit(t_game *game)
{
	game->imgs->exit_o = mlx_xpm_file_to_image(game->mlx, EXIT_O,
			&game->imgs->width, &game->imgs->height);
	game->imgs->exit_c = mlx_xpm_file_to_image(game->mlx, EXIT_C,
			&game->imgs->width, &game->imgs->height);
}

int	init_imgs(t_game *game)
{
	game->imgs = ft_calloc(1, sizeof(t_img));
	if (!game->imgs)
		free_error_exit(game, E_ALLOC);
	game->imgs->floor = mlx_xpm_file_to_image(game->mlx, FLOOR,
			&game->imgs->width, &game->imgs->height);
	game->imgs->wall = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->imgs->width, &game->imgs->height);
	game->imgs->collec = mlx_xpm_file_to_image(game->mlx, COLLEC,
			&game->imgs->width, &game->imgs->height);
	game->imgs->sign = mlx_xpm_file_to_image(game->mlx, SIGN,
			&game->imgs->width, &game->imgs->height);
	game->imgs->bomb = mlx_xpm_file_to_image(game->mlx, BOMB,
			&game->imgs->width, &game->imgs->height);
	init_player(game);
	init_exit(game);
	check_imgs(game);
	return (SUCCESS);
}
