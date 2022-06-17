# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 17:09:23 by yejsong           #+#    #+#              #
#    Updated: 2021/05/25 19:35:02 by yejsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = bmp.c \
		num_valid.c \
		map_valid.c \
		file_valid.c \
		get_fileinfo.c \
		libft.c \
		libft2.c \
		string.c \
		key.c \
		main_loop.c \
		wall_casting.c \
		sort_sprites.c \
		sprites_casting.c \
		game_init.c \
		main.c

MLX = ./mlx

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

NAME			= cub3D

all:			$(NAME)

bonus:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(MLX)
				clang ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS)
				$(RM) screenshot.bmp

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re