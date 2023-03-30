CC=gcc
CFLAGS=-Wall
MAIN_EXE=main

compile:
	make -s clean
	$(CC) $(CFLAGS) -o $(MAIN_EXE) main.c

clean:
	rm -f $(MAIN_EXE)

.SILENT: compile
.SILENT: clean