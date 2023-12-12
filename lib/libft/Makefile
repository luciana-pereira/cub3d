# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 02:19:07 by lucperei          #+#    #+#              #
#    Updated: 2023/12/09 15:31:01 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -I./ -c

# Vou incluir e atualizar lista de funções conforme for necessitando da utilização para não ficar pesado

SRC = ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
# SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_split.c ft_strncpy.c \
# ft_calloc.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_itoa.c ft_strcpy.c \
# ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_toupper.c ft_strcat.c \
# ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_isspace.c \
# ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c get_next_line.c \
# ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c get_next_line_utils.c\

OBJS = $(SRC:.c=.o)

RM = rm -f

AR = ar rc

CC = cc

$(NAME): $(OBJS) libft.h
		$(CC) $(FLAGS) $(SRC)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean: 
		$(RM) $(OBJS)
		
fclean: clean
		$(RM) $(NAME)

re: fclean all
