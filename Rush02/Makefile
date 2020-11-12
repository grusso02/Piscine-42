
NAME = rush-02
SRCS = ${wildcard *.c}
CFLAGS = -g -Wall -Wextra -Werror
OBJ = ${SRCS:.c=.o}
INCLUDE = includes
EXT = *.o *.gch
RM = rm ${EXT}
CLEAR = rm -f ${NAME} ${EXT}

$NAME : all

all: ${OBJ}
	cc -o ${NAME} ${OBJ}
.c.o:
	cc -I ${INCLUDE} ${CFLAGS} -c $< -o ${<:.c=.o}
clean:
	${RM}
fclean:
	${CLEAR}
