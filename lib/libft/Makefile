# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 02:19:07 by lucperei          #+#    #+#              #
#    Updated: 2024/01/07 22:28:01 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

FLAGS			= -Wall -Wextra -Werror -g3
CFLAGS			= -I ./

CC				= cc
AR 				= ar -rcs
RM_F			= -rm -f
RM_RF			= rm -rf

HEADER_LIBFT	= libft.h

SRC				= 	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_substr.c \
					ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_strjoin.c \
					ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_strlen.c \
					get_next_line.c	get_next_line_utils.c ft_putnbr_fd.c \
					ft_strncmp.c ft_strcmp.c ft_strrchr.c ft_strtrim.c \

OBJ_PATH		= obj
OBJ 			= $(SRC:%.c=$(OBJ_PATH)/%.o)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
		@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: src/%.c $(HEADER_LIBFT)
		@$(CC) $(FLAGS) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)

clean:
		@$(RM_F) $(OBJ)

fclean: clean
		@$(RM_F) $(NAME) $(RM_RF) $(OBJ_PATH)

re:		fclean all

.PHONY: all clean fclean re
