# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 15:39:00 by aalliot           #+#    #+#              #
#    Updated: 2014/11/29 22:47:05 by aalliot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
SRC		=
OBJ		= $(SRC:.c=.o)
MLX		= -L/usr/X11/lib -lmlx -lXext -lX11
FLAGS	= -Wall -Wextra -Werror
CC		= gcc

.PHONY: test clean fclean re

all:
	@make -C libft/ fclean
	@make -C libft/
	@gcc -o $(NAME) lib3d.c read_map.c main.c libft/libft.a -L/usr/X11/lib -lmlx -lXext -lX11 -I .
	@./fdf

debug:
	@make -C libft/ fclean
	@make -C libft/
	@gcc -g -o $(NAME) lib3d.c read_map.c main.c libft/libft.a -L/usr/X11/lib -lmlx -lXext -lX11 -I .
	@./fdf

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
