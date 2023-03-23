CC=gcc
CFLAGS=-Wall
MAIN_EXE=main
DIR=/home

check_home:
	$(CC) $(CFLAGS) -o main main.c
	./$(MAIN_EXE) $(DIR)
	make -s clean

clean:
	rm -f $(MAIN_EXE)

.SILENT: check_home
.SILENT: clean
