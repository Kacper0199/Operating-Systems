CC=gcc
CFLAGS=-Wall
MAIN_EXE=main
TST_DIR="./test_folder"

run:
	$(CC) $(CFLAGS) -o $(MAIN_EXE) main.c
	./$(MAIN_EXE) $(DIR)
	make -s clean

test:
	$(CC) $(CFLAGS) -o $(MAIN_EXE) main.c
	./$(MAIN_EXE) $(TST_DIR)
	make -s clean

clean:
	rm -f $(MAIN_EXE)

.SILENT: run
.SILENT: test
.SILENT: clean
