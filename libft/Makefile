CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

test:
	gcc main.c -L. -lft -o main
