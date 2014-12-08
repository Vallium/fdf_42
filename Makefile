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
SRC		= main.c line.c lib3d.c hook.c moving.c read_map.c rotate.c
OBJ		= $(SRC:.c=.o)
HDR		= libft/includes/
MLX		= -L/usr/X11/lib -lmlx -lXext -lX11
FLAGS	= -Wall -Wextra -Werror
CC		= gcc

.PHONY: test clean cleanlib fclean re 42

%.o: %.c
	@$(CC) $(FLAGS) -I $(HDR) -I . -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[H\033[2J"
	@echo "\033[36m...\033[33m╦ ╦╔═╗╦  ╦  ╔═╗  ╦  ╦╔═╗╦  ╦  ╦╦ ╦╔╦╗\033[36m...";
	@echo "\033[36m───\033[33m╠═╣║╣ ║  ║  ║ ║  ╚╗╔╝╠═╣║  ║  ║║ ║║║║\033[36m───";
	@echo "\033[36m   \033[33m╩ ╩╚═╝╩═╝╩═╝╚═╝   ╚╝ ╩ ╩╩═╝╩═╝╩╚═╝╩ ╩\033[0m   ";
	@echo "\033[01m\033[32m\n\xf0\x9f\x91\x8c  COMPILATION DE FDF \xf0\x9f\x91\x8c\n\033[0m"
	@echo "\033[31mTemps de compilation:"
	@time make -C libft/ fclean && make -C libft/ && $(CC) $(FLAGS) $(MLX) -o $(NAME)\
		$(OBJ) libft/libft.a
	@echo "\033[01m\033[32m\n\xf0\x9f\x91\x8c  PROGRAMME COMPILE! \xf0\x9f\x91\x8c\n\033[0m"

clean:
	@rm -f $(OBJ)

cleanlib:
	@make -C libft/ fclean

fclean: clean cleanlib
	@rm -f $(NAME)

re: fclean all
