CC = cc
NAME = bsq
OBJS = ${SRC:.c=.o}

all: ${NAME}

bsq: */*.c
	cc -Wall -Werror -Wextra */*.c *.c -o bsq

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: clean bsq

.PHONY: all clean fclean re

