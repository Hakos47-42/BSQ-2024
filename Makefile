CC = cc
NAME = bsq
OBJS = ${SRC:.c=.o}

all: ${NAME}

bsq: */*.c
	cc -Wall -Werror -Wextra */*.c *.c -o bsq -I include

debug:
	cc -Wall -Werror -Wextra -g */*.c *.c -o bsq -I include

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: clean bsq

.PHONY: all clean fclean re

