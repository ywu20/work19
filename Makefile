all:		interface.o	worker.o
	gcc	-o	1	interface.o
	gcc -o	2	worker.o
interface.o:	interface.c
	gcc	-c	interface.c

worker.o:	worker.c
	gcc	-c	worker.c
