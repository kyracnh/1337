CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME_CLIENT = client
NAME_SERVER = server
NAME_C_BONUS = client_bonus
NAME_S_BONUS = server_bonus

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

SRC_S = server.c ft_atoi/ft_atoi.c
OBJ_S = $(SRC_S:.c=.o)
SRC_C = client.c ft_atoi/ft_atoi.c
OBJ_C = $(SRC_C:.c=.o)

SRC_S_BONUS = server_bonus.c ft_atoi/ft_atoi.c
OBJ_S_BONUS = $(SRC_S_BONUS:.c=.o)
SRC_C_BONUS = client_bonus.c ft_atoi/ft_atoi.c
OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@

all: $(FT_PRINTF_LIB) client server

$(FT_PRINTF_LIB):
	@ $(MAKE) -C $(FT_PRINTF_DIR)

client: ft_printf $(OBJ_C)
	@ $(CC) $(FLAGS) -o $(NAME_CLIENT) $(OBJ_C) $(LIBFTPRINTF)

server: ft_printf $(OBJ_S)
	@ $(CC) $(FLAGS) -o $(NAME_SERVER) $(OBJ_S) $(LIBFTPRINTF)

bonus: $(FT_PRINTF_LIB) client_bonus server_bonus

$(FT_PRINTF_LIB):
	@ $(MAKE) -C $(FT_PRINTF_DIR)

client_bonus: ft_printf $(OBJ_C_BONUS)
	@ $(CC) $(FLAGS) -o $(NAME_C_BONUS) $(OBJ_C_BONUS) $(LIBFTPRINTF)

server_bonus: ft_printf $(OBJ_S_BONUS)
	@ $(CC) $(FLAGS) -o $(NAME_S_BONUS) $(OBJ_S_BONUS) $(LIBFTPRINTF)

ft_printf:
	@ make -C ft_printf/ all

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C) $(OBJ_S_BONUS) $(OBJ_C_BONUS)
	@ make -C ft_printf/ clean

fclean: clean
	@ $(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_C_BONUS) $(NAME_S_BONUS)
	@ make -C ft_printf/ fclean

re: fclean all
