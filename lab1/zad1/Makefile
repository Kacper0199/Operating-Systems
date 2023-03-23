CC = gcc -Wall

static:
	make clean
	$(CC) -c ex1.c
	ar crs ex1.a ex1.o

shared:
	make clean
	$(CC) -shared -o libex1.so -fPIC ex1.c

clean:
	rm -rf *.o *.so *.a

.PHONY: static shared clean
