CC=gcc-mp-5
FLAGS=-O3 -fopenmp -Wall
EXECS=alpha1 alpha2 helloWorld

all: ${EXECS}

alpha1: alpha1.c
	${CC} ${FLAGS} alpha1.c -o alpha1

alpha2: alpha2.c
	${CC} ${FLAGS} alpha2.c -o alpha2

helloWorld: helloWorld.c
	${CC} ${FLAGS} $^ -o helloWorld

clean:
	rm -f ${EXECS}
