/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senku <senku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:38:26 by tkara2            #+#    #+#             */
/*   Updated: 2024/07/20 22:04:08 by senku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_argv(argc, argv);
	game = init_game();
	game.map = init_map(argv[1]);
	game.player = init_player(game.map);		
	return (EXIT_SUCCESS);
}