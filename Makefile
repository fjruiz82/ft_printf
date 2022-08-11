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