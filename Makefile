# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:41:27 by mradwan           #+#    #+#              #
#    Updated: 2022/11/18 15:42:21 by mradwan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c 						\
       ft_printf/ft_printf.c		\
	   ft_printf/ft_supp.c			\
	   gnl/get_next_line.c			\
	   gnl/get_next_line_utils.c	\
	   par.c						\
	   map.c						\
	   player_movement.c			\
	   valid_path.c					\
	   check_all_valid.c			\
	   drawing.c


OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	(cd mlx && make)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
