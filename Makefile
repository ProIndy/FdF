# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 12:37:39 by ijaaskel          #+#    #+#              #
#    Updated: 2023/01/22 12:37:45 by ijaaskel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

FLAGS		=	-Wall -Wextra -Werror

SRC_DIR		=	./src/
INC_DIR		=	./includes/
LIBFT		=	-I libft/includes -L libft -lft

ifneq (,$(wildcard /usr/local/include/mlx.h))
MLX			=	-I /usr/local/include
else
MLX			=	-I /usr/X11/include
endif

ifneq (,$(wildcard /usr/local/lib/libmlx.a))
MLX			+=	-L /usr/local/lib -lmlx
else ifneq (,$(wildcard /usr/local/lib/libmlx.dylib))
MLX			+=	-L /usr/local/lib -lmlx
else
MLX			+=	-L /usr/X11/lib -lmlx
endif

UNAME		:=	$(shell uname -s)
ifeq ($(UNAME), Darwin)
FRAMEWORKS 	=	-framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
MLX			+=	-lX11 -lXext
endif

HDR			=	fdf.h
SRC			=	main.c	error.c	read_map.c	manage_keys.c	\
				draw_images.c	define_image.c	draw_line.c

OBJS		=	main.o	error.o	read_map.o	manage_keys.o	\
				draw_images.o	define_image.o	draw_line.o

all:	$(NAME)

%.o:	%.c	Makefile	fdf.h
	@gcc $(FLAGS) -I libft/includes -c $< -o $@

$(NAME):
	@make -C libft/
	@gcc -c $(addprefix $(SRC_DIR), $(SRC))
	@gcc -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(FLAGS) $(FRAMEWORKS)

clean:
	@make clean -C libft/
	@rm -v -f $(OBJS)
	@rm -v -f *~

fclean:	clean
	@make fclean -C libft/
	@rm -v -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
