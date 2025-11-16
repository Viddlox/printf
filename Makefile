NAME = libftprintf.a

LIBFTDIR = libft

SRC = $(wildcard *.c)

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = $(LIBFTDIR)/libft.a

all: ${NAME}

# --- for testing only ---
test: a.out
a.out: main.o ${NAME}
	${CC} main.o ${NAME} -o a.out
# --- for testing only ---

%.o: %.c
	${CC} ${CFLAGS} -I. -I${LIBFTDIR} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}: ${LIBFT} ${OBJS}
	cp ${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re test
