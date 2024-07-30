/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:37:31 by senku             #+#    #+#             */
/*   Updated: 2024/07/29 17:41:39 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINE_H
# define SO_LONG_DEFINE_H

# define SUCCESS 0
# define FAILURE 1
# define IMG_SZ 64
# define SCR_W 1920
# define SCR_H 1080

# define GAME_NAME "SO_LONG"
# define GAME_WON "You finished the game. Congratulation\n"
# define GAME_LOSE "You've lost the game.\n"
# define GAME_QUIT	"You quit the game.\n"

# define FLOOR	"./assets/floor.xpm"
# define WALL	"./assets/wall.xpm"
# define COLLEC	"./assets/collec.xpm"
# define PLAYER	"./assets/player.xpm"
# define PLAYER_U	"./assets/player_up.xpm"
# define PLAYER_L	"./assets/player_left.xpm"
# define PLAYER_R	"./assets/player_right.xpm"
# define EXIT_C	"./assets/exit_unreachable.xpm"
# define EXIT_O	"./assets/exit_reachable.xpm"
# define SIGN	"./assets/sign.xpm"
# define BOMB	"./assets/bomb.xpm"

# define E_USAGE "Error\nUsage: ./so_long maps/<map.ber>.\n"
# define E_WRONG_EXT "Error\nWrong map file extention.\n"
# define E_OPEN_FILE "Error\nCannot open file.\n"
# define E_READ_FILE "Error\nWhile reading file.\n"
# define E_INVALID_CHAR "Error\nInvalid char in map.\n"
# define E_MAP_NOT_CLOSE "Error\nMap is not closed.\n"
# define E_MAP_CHAR_NBR "Error\nMap contains not enough char.\n"
# define E_MAP_NOT_RECTANGLE "Error\nInvalid map is not rectangular.\n"
# define E_MAP_SIZE "Error\nInvalid number of char in map.\n"
# define E_MAP_EMPTY "Error\nMap empty.\n"
# define E_MAP_PATH "Error\nNo path found to exit or collectibles.\n"
# define E_MAP_WSZ "Error\nThe map width is bigger than the screen length.\n"
# define E_MAP_HSZ "Error\nThe map height is bigger than the screen length.\n"
# define E_ALLOC "Error\nAllocation failed.\n"

# define E_MLX "Error\nWhile initializing mlx.\n"
# define E_MLX_WIN "Error\nWhile creating mlx window.\n"

# define E_INIT_F_IMG "Error\nWhile creating floor image.\n"
# define E_INIT_W_IMG "Error\nWhile creating wall image.\n"
# define E_INIT_C_IMG "Error\nWhile creating collectible image.\n"
# define E_INIT_P_IMG "Error\nWhile creating player image.\n"
# define E_INIT_PL_IMG "Error\nWhile creating player left image.\n"
# define E_INIT_PR_IMG "Error\nWhile creating player right image.\n"
# define E_INIT_PU_IMG "Error\nWhile creating player up image.\n"
# define E_INIT_EO_IMG "Error\nWhile creating exit open image.\n"
# define E_INIT_EC_IMG "Error\nWhile creating exit close image.\n"
# define E_INIT_S_IMG "Error\nWhile creating sign image.\n"
# define E_INIT_B_IMG "Error\nWhile creating bomb image.\n"

#endif