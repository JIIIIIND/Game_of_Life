# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinwkim <jinwkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/22 22:13:59 by jinwkim           #+#    #+#              #
#    Updated: 2020/04/22 23:35:41 by jinwkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= life
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
SRCS	= ./srcs/main.c \
		  ./srcs/life_algorithm.c \
		  ./srcs/print_plane.c
OBJS	= $(SRCS:.c=.o)
INC		= -I./includes
LIB		= -L./libft -lft

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
