# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 14:59:16 by lucperei          #+#    #+#              #
#    Updated: 2023/12/10 05:33:48 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories

# Comandos
CC = cc -g3
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -I./ -c
MLX_FLAGS = -lX11 -lXext -lmlx -lm

# Arquivos
NAME		= cub3D
SRC			= src/main.c \
			  src/error.c \
			  src/free.c \
			  src/utils.c \
			  src/verify_map.c \


LIBFT_PATH  = ./lib/libft
LIBFT 	    = $(LIBFT_PATH)/libft.a

HEADER = include/cub3d.h

# Arquivos e Diretórios
OBJ 	    = $(SRC:.c=.o)

# Cores para saída no terminal
COLOR_RED	= \e[0;31m
COLOR_GREEN	= \e[0;32m
COLOR_PURPLE= \e[0;35m
COLOR_WHITE	= \e[0;37m

# Regras
.SILENT:

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re:	  fclean all 

.PHONY: all clean fclean re  