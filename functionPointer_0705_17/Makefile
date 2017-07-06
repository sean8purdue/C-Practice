# Makefile

pointerFunc: pointerFunction.o memdump.o
	gcc pointerFunction.o memdump.o -o pointerFunc

pointerFunction.o: pointerFunction.c memdump.h
	gcc -c pointerFunction.c

memdump.o: memdump.c memdump.h
	gcc -c memdump.c

clean:
	rm -rf *.o pointerFunc
