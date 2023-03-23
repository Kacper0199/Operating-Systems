CC = gcc -Wall

static:
	make clean
	$(CC) -c ex1.c
	ar crs ex1.a ex1.o
	$(CC) -c main.c
	$(CC) main.o ex1.o -o main

shared:
	make clean
	$(CC) -fPIC -c ex1.c -o ex1_shared.o
	$(CC) -shared ex1_shared.o -o libex1_shared.so
	$(CC) -c main.c -o main_shared.o
	$(CC) main_shared.o -L. -Wl,-rpath=. -lex1_shared -o main_shared

dynamic:
	make clean
	$(CC) -fPIC -c ex1.c -o ex1_dyn.o
	$(CC) -shared ex1_dyn.o -o libex1_dyn.so
	$(CC) -c -DDYNAMIC main.c -o main_dyn.o
	$(CC) main_dyn.o -L. -Wl,-rpath=. -lex1_dyn -o main_dyn

clean:
	rm -rf *.o *.so *.a

.PHONY: static shared dynamic clean
