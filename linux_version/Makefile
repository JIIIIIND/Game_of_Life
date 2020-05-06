# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/22 22:13:59 by jinwkim           #+#    #+#              #
#    Updated: 2020/05/06 21:26:58 by jinwkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= life
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -D BUFFER_SIZE=16
SRCS	= ./srcs/main.c \
		  ./srcs/life_algorithm.c \
		  ./srcs/win_main.c \
		  ./srcs/camera.c \
		  ./srcs/mouse_event.c \
		  ./srcs/keyboard_event.c \
		  ./srcs/draw_ui.c \
		  ./srcs/draw_btn.c \
		  ./srcs/btn_event.c \
		  ./srcs/camera_move.c \
		  ./srcs/get_next_line.c \
		  ./srcs/save_file.c
OBJS	= $(SRCS:.c=.o)
INC		= -I./includes
LIB		= -L./Library -lft -lmlx -lX11 -lXext -lbsd -lm

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
