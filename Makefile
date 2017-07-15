# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 19:27:32 by dcastro-          #+#    #+#              #
#    Updated: 2017/07/14 18:00:38 by dcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -Wall -Werror -Wextra -g

SRCS = srcs/main.c srcs/check_valid.c srcs/storage.c
SRCDIR = srcs/

OBJ = $(SRCS:.c=.o)
SRC = $(addprefix $(SRCDIR), $(SRCS))

INCLUDE = -L libft/ -lft -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) 
	make -C minilibx_macos
	make -C libft
	$(CC) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean


