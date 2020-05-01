# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/22 22:13:59 by jinwkim           #+#    #+#              #
#    Updated: 2020/05/01 21:15:51 by jinwkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= life
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ./srcs/main.c \
		  ./srcs/life_algorithm.c \
		  ./srcs/win_main.c \
		  ./srcs/camera.c \
		  ./srcs/print_plane.c \
		  ./srcs/mouse_event.c \
		  ./srcs/keyboard_event.c \
		  ./srcs/draw_ui.c
OBJS	= $(SRCS:.c=.o)
INC		= -I./includes
LIB		= -L./Library -lft -lmlx -lX11 -lXext -lm

all:	$(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INC)

$(NAME): $(OBJS)
		 $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC) $(LIB)
		
clean:
		rm -rf $(OBJS)
fclean:	clean
		rm -rf $(NAME)
re:		fclean all
