CC = gcc
CFLAGS1 = -Wall -g
CFLAGS2 = -c
VPATH = SRC INCLUDE 

# Link the two object files together.

main: main.o backsubst.o mat_io.o gauss.o
	${CC} ${CFLAGS1} main.o backsubst.o mat_io.o gauss.o

# Compile each source file to an object.

main.o: main.c
	${CC} ${CFLAGS2} main.c 

backsubst.o: backsubst.c
	${CC} ${CFLAGS2} backsubst.c

mat_io.o: mat_io.c
	${CC} ${CFLAGS2} mat_io.c

gauss.o: gauss.c
	${CC} ${CFLAGS2} -lm gauss.c


