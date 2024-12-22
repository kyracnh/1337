CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME_CLIENT = client
NAME_SERVER = server

SRC_S = server.c ft_atoi/ft_atoi.c
OBJ_S = $(SRC_S:.c=.o)
SRC_C = client.c ft_atoi/ft_atoi.c
OBJ_C = $(SRC_C:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@

all: client server

client: ft_printf $(OBJ_C)
	@ $(CC) $(FLAGS) -o $(NAME_CLIENT) $(OBJ_C) $(LIBFTPRINTF)

server: ft_printf $(OBJ_S)
	@ $(CC) $(FLAGS) -o $(NAME_SERVER) $(OBJ_S) $(LIBFTPRINTF)

ft_printf:
	@ make -C ft_printf/ all

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C)
	@ make -C ft_printf/ clean

fclean: clean
	@ $(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@ make -C ft_printf/ fclean

re: fclean all
