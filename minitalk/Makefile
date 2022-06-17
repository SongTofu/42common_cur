# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: song-yejin <song-yejin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 17:15:43 by song-yejin        #+#    #+#              #
#    Updated: 2021/08/07 19:07:47 by song-yejin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		server

NAME2 =		client

NAME3 =		server_bonus

NAME4 =		client_bonus

CFLAGS +=	-Wall -Wextra -Werror

LIBSRC =	libft.c

SRCS1 =		server.c
SRCSB1 =	server_bonus.c

SRCS2 =		client.c \
			send.c
SRCSB2 =	client_bonus.c \
			send_bonus.c

LIBOBJ =	$(LIBSRC:.c=.o)

OBJS1 =		$(SRCS1:.c=.o)
OBJS2 =		$(SRCS2:.c=.o)

OBJS3 =		$(SRCSB1:.c=.o)
OBJS4 =		$(SRCSB2:.c=.o)

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJS1) $(LIBOBJ)
			gcc $(CFLAGS) $(OBJS1) $(LIBOBJ) -o $(NAME)

$(NAME2):	$(OBJS2) $(LIBOBJ)
			gcc $(CFLAGS) $(OBJS2) $(LIBOBJ) -o $(NAME2)

$(NAME3):	$(OBJS3) $(LIBOBJ)
			gcc $(CFLAGS) $(OBJS3) $(LIBOBJ) -o $(NAME3)

$(NAME4):	$(OBJS4) $(LIBOBJ)
			gcc $(CFLAGS) $(OBJS4) $(LIBOBJ) -o $(NAME4)

bonus:		$(NAME3) $(NAME4)

clean:
			rm -f $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4) $(LIBOBJ)
			rm -f $(SRCSB1:.c=.o) $(SRCSB2:.c=.o)

fclean:		clean
			rm -f $(NAME) $(NAME2) $(NAME3) $(NAME4) $(LIBOBJ)

re: 		fclean all

.PHONY:		re clean fclean all bonus