# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 15:39:00 by aalliot           #+#    #+#              #
#    Updated: 2014/12/05 16:00:03 by aalliot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
SRC		= main.c line.c lib3d.c hook.c moving.c read_map.c
OBJ		= $(SRC:.c=.o)
MLX		= -L/usr/X11/lib -lmlx -lXext -lX11
FLAGS	= -Wall -Wextra -Werror
CC		= gcc

.PHONY: test clean fclean re 42

all:
	@echo "\033[H\033[2J"
	@echo "\033[36m...\033[33m╦ ╦╔═╗╦  ╦  ╔═╗  ╦  ╦╔═╗╦  ╦  ╦╦ ╦╔╦╗\033[36m...";
	@echo "\033[36m───\033[33m╠═╣║╣ ║  ║  ║ ║  ╚╗╔╝╠═╣║  ║  ║║ ║║║║\033[36m───";
	@echo "\033[36m   \033[33m╩ ╩╚═╝╩═╝╩═╝╚═╝   ╚╝ ╩ ╩╩═╝╩═╝╩╚═╝╩ ╩\033[0m   ";
	@echo "\033[01m\033[32m\n\xf0\x9f\x91\x8c  COMPILATION DE FDF \xf0\x9f\x91\x8c\n\033[0m"
	@echo "\033[31mTemps de compilation:"
	@time make -C libft/ fclean && make -C libft/ && $(CC) $(FLAGS) -o $(NAME)\
		$(SRC) libft/libft.a -L/usr/X11/lib \
		-lmlx -lXext -lX11 -I .
	@echo "\033[01m\033[32m\n\xf0\x9f\x91\x8c  PROGRAMME COMPILE! \xf0\x9f\x91\x8c\n\033[0m"

42:
	@echo "\033[H\033[2J"
	@echo "\033[36m...\033[33m╦ ╦╔═╗╦  ╦  ╔═╗  ╦  ╦╔═╗╦  ╦  ╦╦ ╦╔╦╗\033[36m...";
	@echo "\033[36m───\033[33m╠═╣║╣ ║  ║  ║ ║  ╚╗╔╝╠═╣║  ║  ║║ ║║║║\033[36m───";
	@echo "\033[36m   \033[33m╩ ╩╚═╝╩═╝╩═╝╚═╝   ╚╝ ╩ ╩╩═╝╩═╝╩╚═╝╩ ╩\033[0m   ";
	@echo "\033[01m\033[32m\n\xf0\x9f\x91\x8c  COMPILATION DE FDF \xf0\x9f\x91\x8c\n\033[0m"
	@echo "\033[31mTemps de compilation:"
	@time make -C libft/ fclean && make -C libft/ && $(CC) $(FLAGS) -o $(NAME)\
		$(SRC) libft/libft.a -L/usr/X11/lib \
		-lmlx -lXext -lX11 -I .
	@echo "\033[36m\nTemps d'execution du programme:\n"
	@time -p ./fdf map_fdf/42.fdf
	@echo "\033[01m\033[32m\n\xf0\x9f\x91\x8c  PROGRAMME TERMINE! \xf0\x9f\x91\x8c\n\033[0m"

debug:
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) $(FLAGS) -g -o $(NAME) lib3d.c read_map.c main.c \
		libft/libft.a -L/usr/X11/lib -lmlx -lXext -lX11 -I .
	@./fdf

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
