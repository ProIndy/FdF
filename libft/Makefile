# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 19:50:54 by ijaaskel          #+#    #+#              #
#    Updated: 2021/11/03 19:59:16 by ijaaskel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

FLAGS		=	-Wall -Wextra -Werror

INC			=	./includes/
SRC_DIR		=	./
PF_DIR		=	./ft_printf/

HDR			=	libft.h

LFT_SRC		=	ft_memset.c	ft_bzero.c	ft_memcpy.c	ft_memccpy.c \
				ft_memmove.c	ft_memchr.c	ft_memcmp.c	ft_strlen.c \
				ft_strdup.c	ft_strcpy.c	ft_strncpy.c	ft_strcat.c \
				ft_strncat.c	ft_strlcat.c	ft_strchr.c	ft_strrchr.c \
				ft_strstr.c	ft_strnstr.c	ft_strcmp.c	ft_strncmp.c \
				ft_atoi.c	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c \
				ft_isascii.c	ft_isprint.c	ft_toupper.c	ft_tolower.c \
				ft_memalloc.c	ft_memdel.c	ft_strnew.c	ft_strdel.c \
				ft_strclr.c	ft_striter.c	ft_striteri.c	ft_strmap.c \
				ft_strmapi.c	ft_strequ.c	ft_strnequ.c	ft_strsub.c \
				ft_strjoin.c	ft_strtrim.c	ft_strsplit.c	ft_itoa.c \
				ft_putchar.c	ft_putstr.c	ft_putendl.c	ft_putnbr.c \
				ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c \
				ft_putnbr_fd.c	ft_islower.c	ft_isupper.c \
				ft_iswhitespace.c	ft_numlen.c	ft_array_size.c \
				get_next_line.c

PF_SRC		=	ft_printf.c	ft_error_exit.c	ft_parse_conv.c	ft_write_conv.c \
				ft_validity_checkers.c	ft_init_reset_conv.c \
				ft_write_int.c	ft_write_string.c	ft_write_unsigned.c \
				ft_write_float.c	ft_helpers.c	ft_helpers2.c \
				ft_float_rounding.c

LFT_OBJS	=	$(LFT_SRC:.c=.o)
PF_OBJS		=	$(PF_SRC:.c=.o)

all:	$(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix $(PF_DIR), $(PF_SRC))
	@gcc $(FLAGS) -c $(addprefix $(SRC_DIR), $(LFT_SRC))
	@ar rcs $(NAME) $(LFT_OBJS) $(PF_OBJS)

clean:
	@rm -v -f $(LFT_OBJS) $(PF_OBJS)
	@rm -v -f *~

fclean:	clean
	@rm -v -f $(NAME)

re:		fclean
	@make

.PHONY:	all clean fclean re