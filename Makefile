# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 17:32:53 by stherkil          #+#    #+#              #
#    Updated: 2019/07/18 20:03:48 by stherkil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = fdf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ./fdf.h

SRC		= main.c line.c keyboard.c keyboard2.c import.c draw.c gridinit.c gridedit.c get_next_line.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME) -I /usr/local/include  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
