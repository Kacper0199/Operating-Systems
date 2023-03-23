CC=gcc
CFLAGS=-Wall
MAIN_EXE=main

run:
	$(CC) $(CFLAGS) -o main main.c directory.c
	./$(MAIN_EXE)
	make -s clean

clean:
	rm -f $(MAIN_EXE)

.SILENT: run
.SILENT: clean
