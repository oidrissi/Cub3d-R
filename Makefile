# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 08:14:27 by ablaamim          #+#    #+#              #
#    Updated: 2022/09/20 10:36:15 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

FLAGS = -Wall -Wextra -Werror
#MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

HEADER = ./includes/cub3D.h 

SRCS = ./sources/main.c \
	   ./sources/libft_utils_1.c \
	   ./sources/error_handling.c \
	   ./sources/map_parser.c \
	   ./sources/get_next_line.c \

OBJ = $(patsubst %.c,%.o,$(SRCS))

all = $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit  $(OBJ) -o $(NAME)

%.o : %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) cub3D $(OBJ)


re : fclean all

.PHONY : all clean fclean re
