
all: main.o Api.o Api_c_wrapper.o
	g++ *.o -o PROGRAM

Api_c_wrapper.o:
	g++ Api_c_wrapper.cpp -c

Api.o:
	g++ Api.cpp -c

main.o:
	gcc main.c -c

