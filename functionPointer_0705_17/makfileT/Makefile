
geom: geom.o get_double.o
	gcc -o geom geom.o get_double.o

geom.o: geom.c
	gcc -c geom.c

get_double.o: get_double.c
	gcc -c get_double.c

clean:
	rm -f *.o geom
