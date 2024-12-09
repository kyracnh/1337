CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_itoa.c ft_printf.c ft_putchar.c ft_putstr.c ft_strlen.c \
			ft_puthex.c ft_putptr.c ft_putunbr.c ft_puthex_u.c \
			ft_putnbr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	gcc -L. main.c -lftprintf -o main
	./main