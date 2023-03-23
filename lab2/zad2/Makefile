CC=gcc
CFLAGS=-Wall
TEST_OUT_ONE=test_out_one
TEST_OUT_BLOCK=test_out_block
TMP=tmp
MAIN_EXE=main

main_one: reverse_one.o main.c
	$(CC) $(CFLAGS) -o $(MAIN_EXE)_one reverse_one.o main.c

main_block: reverse_block.o main.c
	$(CC) $(CFLAGS) -o $(MAIN_EXE)_block reverse_block.o main.c -DBLOCK

test:
	echo "----------MAKING TESTS----------"
	make -s clean
	$(CC) $(CFLAGS) -c reverse.c -o reverse_one.o
	$(CC) $(CFLAGS) -c reverse.c -o reverse_block.o -DBLOCK
	make -s $(MAIN_EXE)_one
	make -s $(MAIN_EXE)_block
	./$(MAIN_EXE)_one test_in $(TEST_OUT_ONE)
	./$(MAIN_EXE)_block test_in $(TEST_OUT_BLOCK)
	make -s clean_without_out
	echo "--------------------------------"

compare:
	make -s test
	echo "-----------COMPARING------------"
	tac < test_in | rev > temp_file
	diff -s $(TEST_OUT_ONE) temp_file
	diff -s $(TEST_OUT_BLOCK) temp_file
	echo "--------------------------------"

clean_without_out:
	rm -f *.o *.a *.so $(MAIN_EXE)_one $(MAIN_EXE)_block $(MAIN_EXE)

clean:
	rm -f *.o *.a *.so $(TEST_OUT_ONE) $(TEST_OUT_BLOCK) $(MAIN_EXE)_one $(MAIN_EXE)_block $(MAIN_EXE) temp_file

.SILENT: compare
.SILENT: test
.SILENT: clean_without_out
.SILENT: clean
