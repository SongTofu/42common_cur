# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejsong <yejsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 18:35:02 by song-yejin        #+#    #+#              #
#    Updated: 2021/11/02 16:49:08 by yejsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS	= -O3 -Wall -Wextra -Werror -I.

MLXFLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

RM = rm -f

SRCS =	file.c\
		lst.c\
		get_a_line.c\
		key.c\
		main.c\
		main_loop.c\
		map_ck.c\
		string.c\
		utils.c

OBJS = $(SRCS:.c=.o)

MLX = ./mlx

all :	$(NAME)

$(NAME) :	$(OBJS)
			make -C $(MLX)
			clang $(CFLAGS) -o $(NAME) ${OBJS} ${MLXFLAG}

clean:
			@$(MAKE) -C mlx clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re