CC=gcc
CFLAGS=-Wall
MAIN_EXE=main

run:
	$(CC) $(CFLAGS) -o $(MAIN_EXE) main.c
	./$(MAIN_EXE) $(N)
	make -s clean

clean:
	rm -f $(MAIN_EXE)

.SILENT: run
.SILENT: clean
