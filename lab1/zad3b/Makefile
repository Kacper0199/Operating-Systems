CC = gcc -Wall

all_tst:
	make all_static_tst
	make all_shared_tst
	make all_dynamic_tst

all_static_tst:
	make clean
	make static_tst_O_0
	make static_tst_O_2
	make static_tst_O_3

all_shared_tst:
	make clean
	make shared_tst_O_0
	make shared_tst_O_2
	make shared_tst_O_3

all_dynamic_tst:
	make clean
	make dynamic_tst_O_0
	make dynamic_tst_O_2
	make dynamic_tst_O_3

static_O_0:
	make clean
	$(CC) -c ex1.c
	ar crs ex1.a ex1.o
	$(CC) -c main.c
	$(CC) -O0 main.o ex1.o -o main_O_0

static_O_2:
	make clean
	$(CC) -c ex1.c
	ar crs ex1.a ex1.o
	$(CC) -c main.c
	$(CC) -O2 main.o ex1.o -o main_O_2

static_O_3:
	make clean
	$(CC) -c ex1.c
	ar crs ex1.a ex1.o
	$(CC) -c main.c
	$(CC) -O3 main.o ex1.o -o main_O_3

shared_O_0:
	make clean
	$(CC) -fPIC -c ex1.c -o ex1_shared.o
	$(CC) -shared ex1_shared.o -o libex1_shared.so
	$(CC) -c main.c -o main_shared.o
	$(CC) -O0 main_shared.o -L. -Wl,-rpath=. -lex1_shared -o main_shared_O_0

shared_O_2:
	make clean
	$(CC) -fPIC -c ex1.c -o ex1_shared.o
	$(CC) -shared ex1_shared.o -o libex1_shared.so
	$(CC) -c main.c -o main_shared.o
	$(CC) -O2 main_shared.o -L. -Wl,-rpath=. -lex1_shared -o main_shared_O_2

shared_O_3:
	make clean
	$(CC) -fPIC -c ex1.c -o ex1_shared.o
	$(CC) -shared ex1_shared.o -o libex1_shared.so
	$(CC) -c main.c -o main_shared.o
	$(CC) -O3 main_shared.o -L. -Wl,-rpath=. -lex1_shared -o main_shared_O_3

dynamic_O_0:
	make clean
	$(CC) -fPIC -c ex1.c -o ex1_dyn.o
	$(CC) -shared ex1_dyn.o -o libex1_dyn.so
	$(CC) -c -DDYNAMIC main.c -o main_dyn.o
	$(CC) -O0 main_dyn.o -L. -Wl,-rpath=. -lex1_dyn -o main_dyn_O_0

dynamic_O_2:
	make clean
	$(CC) -fPIC -c ex1.c -o ex1_dyn.o
	$(CC) -shared ex1_dyn.o -o libex1_dyn.so
	$(CC) -c -DDYNAMIC main.c -o main_dyn.o
	$(CC) -O2 main_dyn.o -L. -Wl,-rpath=. -lex1_dyn -o main_dyn_O_2

dynamic_O_3:
	make clean
	$(CC) -fPIC -c ex1.c -o ex1_dyn.o
	$(CC) -shared ex1_dyn.o -o libex1_dyn.so
	$(CC) -c -DDYNAMIC main.c -o main_dyn.o
	$(CC) -O3 main_dyn.o -L. -Wl,-rpath=. -lex1_dyn -o main_dyn_O_3

static_tst_O_0:
	make clean
	make static_O_0
	cat cmd_tst | ./main_O_0 >> report_static_O_0.txt

static_tst_O_2:
	make clean
	make static_O_2
	cat cmd_tst | ./main_O_2 >> report_static_O_2.txt

static_tst_O_3:
	make clean
	make static_O_3
	cat cmd_tst | ./main_O_3 >> report_static_O_3.txt

shared_tst_O_0:
	make clean
	make shared_O_0
	cat cmd_tst | ./main_shared_O_0 >> report_shared_O_0.txt

shared_tst_O_2:
	make clean
	make shared_O_2
	cat cmd_tst | ./main_shared_O_2 >> report_shared_O_2.txt

shared_tst_O_3:
	make clean
	make shared_O_3
	cat cmd_tst | ./main_shared_O_3 >> report_shared_O_3.txt

dynamic_tst_O_0:
	make clean
	make dynamic_O_0
	cat cmd_tst | ./main_dyn_O_0 >> report_dynamic_O_0.txt

dynamic_tst_O_2:
	make clean
	make dynamic_O_2
	cat cmd_tst | ./main_dyn_O_2 >> report_dynamic_O_2.txt

dynamic_tst_O_3:
	make clean
	make dynamic_O_3
	cat cmd_tst | ./main_dyn_O_3 >> report_dynamic_O_3.txt

clean:
	rm -rf *.o *.so *.a
