NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
LIBC = ar -rcs
RM = rm -rf
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: ${NAME}

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
