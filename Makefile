# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkara2 <tkara2@student.42.ft>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 11:36:41 by tkara2            #+#    #+#              #
#    Updated: 2024/07/28 19:55:00 by tkara2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAMEB		=	so_long_bonus

SRCS_FILES	=	main.c \
				error.c \
				free_utils.c \
				check_argv.c \
				check_map.c \
				check_map_utils.c \
				read_map.c \
				init_map.c \
				handle_mlx.c \
				player_move.c \
				render_game.c \
				set_game_data.c \
				flood_fill.c \
				game_condition.c \

SRCSB_FILES	=	main_bonus.c \
				error_bonus.c \
				free_utils_bonus.c \
				check_argv_bonus.c \
				check_map_bonus.c \
				check_map_utils_bonus.c \
				read_map_bonus.c \
				init_map_bonus.c \
				handle_mlx_bonus.c \
				player_move_bonus.c \
				render_game_bonus.c \
				set_game_data_bonus.c \
				flood_fill_bonus.c \
				game_condition_bonus.c \

INC_FILE	=	so_long.h define_str.h

SRCS_PATH	=	srcs/
OBJS_PATH	=	.objs/
INC_PATH	=	include/

SRCSB_PATH	=	srcs_bonus/

LIBFT_PATH	=	./lib/libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a

MLX_PATH	=	./lib/mlx-linux/
MLX_LIB		=	$(MLX_PATH)libmlx_Linux.a

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
SRCSB		=	$(addprefix $(SRCSB_PATH), $(SRCSB_FILES))
OBJSB		=	$(addprefix $(OBJS_PATH), $(SRCSB:.c=.o))
INC			=	$(addprefix $(INC_PATH), $(INC_FILE))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g3 -I$(INC_PATH) -I$(LIBFT_PATH) -I$(MLX_PATH)
LFLAGS		=	-L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm
RM			=	rm -rf

NORM_FLAG	=	-R CheckForbiddenSourceHeader -R CheckDefine

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(NAMEB):	$(OBJSB) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJSB) $(LFLAGS) -o $(NAMEB)

$(OBJS_PATH)%.o:	%.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH) --silent

$(MLX_LIB):
	@make -C $(MLX_PATH) --silent

bonus:	$(NAMEB)

norm:
	@norminette $(NORM_FLAG) $(SRCS) $(SRCSB) $(INC)

lftnorm:
	@make norm -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@echo "[DONE] Objects files deletion..."

fclean:	clean
	$(RM) $(NAME) $(NAMEB)
	@make fclean -C $(LIBFT_PATH)
	@echo "[DONE] so_long deletion..."

re:	fclean all
	@echo "[DONE] so_long recompiled..."

.PHONY:	all clean fclean re