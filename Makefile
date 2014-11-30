# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 15:39:00 by aalliot           #+#    #+#              #
#    Updated: 2014/11/30 21:32:53 by aalliot          ###   ########.fr        #
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
	@echo "\033[H\033[2J"
	@echo "\033[01m\033[32m\033[41m| COMPILATION DE FDF |\n\033[0m"
	@echo "\033[31mTemps de compilation:"
	@time make -C libft/ fclean && make -C libft/ && gcc -o $(NAME) \
		lib3d.c read_map.c main.c libft/libft.a -L/usr/X11/lib \
		-lmlx -lXext -lX11 -I .
	@echo "\033[36m\nTemps d'execution du programme:\n"
	@time -p ./fdf
	@echo "\033[01m\033[32m\033[41m\n| PROGRAMME TERMINE! |\033[0m"

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
