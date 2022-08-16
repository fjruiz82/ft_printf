# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 15:30:16 by fruiz-ca          #+#    #+#              #
#    Updated: 2022/08/13 15:30:19 by fruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -I.
SRC=ft_printf.c ft_printf_rest.c ft_printf_ptr.c ft_printf_int.c ft_printf_uint.c ft_printf_hex.c
OBJ=*.o

all: $(NAME)

$(NAME): $(OBJ)
		ar -crs $(NAME) $(OBJ)

$(OBJ): $(SRC)
		$(CC) $(CFLAGS) $(OPTIONS) $(SRC)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re