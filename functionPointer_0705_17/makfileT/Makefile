
all: geom tip

geom: geom.o get_double.o
	gcc -o geom geom.o get_double.o

geom.o: geom.c
	gcc -c geom.c

get_double.o: get_double.c
	gcc -c get_double.c

tip: tip.o get_double.o
	gcc tip.o get_double.o -o tip

tip.o: tip.c
	gcc -c tip.c

clean:
	rm -f *.o geom tip
