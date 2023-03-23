CC=gcc
CFLAGS=-Wall
TEST_OUT_LIB=test_out_lib.txt
TEST_OUT_SYS=test_out_sys.txt
TMP=tmp
MAIN_EXE=main

main_sys: replace_sys.o main.c
	$(CC) $(CFLAGS) -o $(MAIN_EXE)_sys replace_sys.o main.c

main_lib: replace_lib.o main.c
	$(CC) $(CFLAGS) -o $(MAIN_EXE)_lib replace_lib.o main.c -DLIB

test:
	echo "----------MAKING TESTS----------"
	make -s clean
	$(CC) $(CFLAGS) -c replace.c -o replace_sys.o
	$(CC) $(CFLAGS) -c replace.c -o replace_lib.o -DLIB
	make -s $(MAIN_EXE)_sys
	make -s $(MAIN_EXE)_lib
	./$(MAIN_EXE)_sys 'a' 'b' test_in.txt $(TEST_OUT_SYS)
	./$(MAIN_EXE)_lib 'a' 'b' test_in.txt $(TEST_OUT_LIB)
	make -s clean_without_out
	echo "--------------------------------"

compare:
	make -s test
	echo "-----------COMPARING------------"
	tr 'a' 'b' < test_in.txt > $(TMP)
	diff -s $(TMP) $(TEST_OUT_SYS)
	diff -s $(TMP) $(TEST_OUT_LIB)
	echo "--------------------------------"

clean_without_out:
	rm -f *.o *.a *.so $(MAIN_EXE)_sys $(MAIN_EXE)_lib $(MAIN_EXE)

clean:
	rm -f *.o *.a *.so $(TEST_OUT_LIB) $(TEST_OUT_SYS) $(TMP) $(MAIN_EXE)_sys $(MAIN_EXE)_lib $(MAIN_EXE)

.SILENT: compare
.SILENT: test
.SILENT: clean_without_out
.SILENT: clean
