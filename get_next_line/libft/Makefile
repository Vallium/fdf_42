# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 11:30:22 by aalliot           #+#    #+#              #
#    Updated: 2014/11/28 14:24:00 by aalliot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_toupper.c ft_tolower.c ft_strtrim.c ft_strsub.c ft_strstr.c \
		  ft_strrchr.c ft_strnstr.c ft_strnew.c ft_strnequ.c ft_strncpy.c \
		  ft_strncmp.c ft_strncat.c ft_strmapi.c ft_strmap.c ft_strlen.c \
		  ft_strlcat.c ft_strjoin.c ft_striteri.c ft_striter.c ft_strequ.c \
		  ft_strdup.c ft_strdel.c ft_strcpy.c ft_strcmp.c ft_strclr.c \
		  ft_strchr.c ft_strcat.c ft_putstr_fd.c ft_putstr.c ft_putnbr_fd.c \
		  ft_putnbr.c ft_putendl_fd.c ft_putendl.c ft_putchar_fd.c \
		  ft_putchar.c ft_memset.c ft_memmove.c ft_memdel.c ft_memcpy.c \
		  ft_memcmp.c ft_memchr.c ft_memccpy.c ft_memalloc.c ft_isprint.c \
		  ft_isdigit.c ft_isascii.c ft_isalpha.c ft_isalnum.c ft_bzero.c \
		  ft_atoi.c ft_strsplit.c ft_itoa.c \
		  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		  ft_lstiter.c
OBJ		= $(SRC:.c=.o)
HDR		= includes/
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(HDR) -o $@ -c $?

.PHONY: clean fclean re test1 test2 testall

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
