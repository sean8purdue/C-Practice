cc = gcc

mul:	multiFile.o memdum.o
	gcc -o mul multiFile.o memdum.o

multiFile.o:	multiFile.c	header.h
	gcc -c multiFile.c

memdum.o:	memdum.c
	gcc -c memdum.c
	

clean:
	rm -rf mul *.o
	
