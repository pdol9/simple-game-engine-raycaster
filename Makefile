# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 17:09:43 by mluik             #+#    #+#              #
#    Updated: 2022/12/02 12:35:16 by mluik            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -O3
RM			:=	rm -rf

# dependencies
INC			:=	include
LIBFT_DIR 	:=	./libft
INC_L		:=	$(LIBFT_DIR)/$(INC)
LIBFT 		:=	$(LIBFT_DIR)/libft.a
HEADER		:=	$(INC)/cub3d.h
HEADER_L	:=	$(LIBFT_DIR)/$(INC)/libft.h

# minilibx dependencies
MLX_FLAGS	:=	-I /usr/X11/include -L /usr/X11/lib -L ./mlx -lmlx -lm -lX11 -lXext -lz
MLX			:= ./mlx

# miscellaneous
CLEAR := \033[0m
PR := \033[1;35m
GR := \033[1;32m

# source dir
SRCS_DIR :=	srcs
MAIN_DIR := /main/
MISC_DIR := /misc/
PLAYER_DIR := /player/
RENDER_DIR := /render/
PARS_DIR := /pars/

# source files
MAIN := main.c
MISC := exit.c init.c init_mlx.c init_game.c get_next_line.c get_next_line_utils.c str.c
PLAYER := move_01.c move_02.c pos_player.c
RENDER := render.c render_utils.c raycasting.c textures.c
PARS := parse_meta.c savemeta.c layout.c check_file.c parse_rgb.c parse_rgb_2.c

SRCS	=	$(addprefix $(SRCS_DIR), $(addprefix $(MAIN_DIR), $(MAIN))) \
			$(addprefix $(SRCS_DIR), $(addprefix $(MISC_DIR), $(MISC))) \
			$(addprefix $(SRCS_DIR), $(addprefix $(PLAYER_DIR), $(PLAYER))) \
			$(addprefix $(SRCS_DIR), $(addprefix $(RENDER_DIR), $(RENDER))) \
			$(addprefix $(SRCS_DIR), $(addprefix $(PARS_DIR), $(PARS)))

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

all: $(LIBFT) $(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) all -s -C $(MLX)
			@$(CC) -o $@ $^ $(LIBFT) $(MLX_FLAGS)
	@echo "$(GR)							\n \
░█████╗░██╗░░░██╗██████╗░██████╗░██████╗░	\n \
██╔══██╗██║░░░██║██╔══██╗╚════██╗██╔══██╗	\n \
██║░░╚═╝██║░░░██║██████╦╝░█████╔╝██║░░██║	\n \
██║░░██╗██║░░░██║██╔══██╗░╚═══██╗██║░░██║	\n \
╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝	\n \
░╚════╝░░╚═════╝░╚═════╝░╚═════╝░╚═════╝░	\n \
	> Compiled & linked!				$(REV)"

%.o:%.c $(HEADER) $(HEADER_L)
	@$(CC) $(CFLAGS) -I $(INC) -I $(INC_L) -c $< -o $@

$(LIBFT):
	@$(MAKE) all -s -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@echo "$(PR)All object files deleted$(CLEAR)"

fclean:		clean
			$(RM) $(NAME)
			make clean -C $(MLX)

norm:
	@norminette $(SRCS_DIR) $(INC)

re:	fclean all

.PHONY: all clean fclean re norm
