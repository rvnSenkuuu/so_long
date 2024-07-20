# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 11:36:41 by tkara2            #+#    #+#              #
#    Updated: 2024/07/19 19:22:13 by tkara2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS_FILES	=	main.c \
				put_error.c \
				free_utils.c \
				check_argv.c \
				check_map_valid.c \
				check_map_utils.c \
				read_map.c \
				init_game_structure.c \
				set_game_data.c \

INC_FILE	=	so_long.h

SRCS_PATH	=	srcs/
OBJS_PATH	=	.objs/
INC_PATH	=	include/

LIBFT_PATH	=	./lib/libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a

MLX_PATH	=	./lib/mlx-linux/
MLX_LIB		=	$(MLX_PATH)libmlx_Linux.a

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
INC			=	$(addprefix $(INC_PATH), $(INC_FILE))

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I$(INC_PATH) -I$(LIBFT_PATH) -I$(MLX_PATH)
LFLAGS	=	-L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm
RM		=	rm -rf

NORM_FLAG	=	-R CheckForbiddenSourceHeader -R CheckDefine

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJS_PATH)%.o:	%.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH) --silent

$(MLX_LIB):
	@make -C $(MLX_PATH) --silent

norm:
	@make norm -C $(LIBFT_PATH)
	@norminette $(NORM_FLAG) $(SRCS) $(INC)

clean:
	$(RM) $(OBJS_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@echo "[DONE] Objects files deletion..."

fclean:	clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "[DONE] so_long deletion..."

re:	fclean all
	@echo "[DONE] so_long recompiled..."

.PHONY:	all clean fclean re