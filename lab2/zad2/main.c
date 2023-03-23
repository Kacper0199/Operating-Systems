#include "reverse.h"
#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Wrong number of arguments");
        return -1;
    }

    FILE *fp = fopen("pomiar_zad_2.txt", "a+");
    clock_t start_clock; 
    clock_t end_clock;
    double cpu_time_used;

#ifdef BLOCK
    start_clock = clock();
    int out_descr = reverse_by_block(argv[1], argv[2]);
    if (out_descr == -1) {
        printf("Error when reversing file by block\n");
        return -1;
    }
    end_clock = clock();

    cpu_time_used = ((double) (end_clock - start_clock)) / CLOCKS_PER_SEC;
    printf("Time taken reversing by block: %f seconds\n", cpu_time_used);
    fprintf(fp, "Time taken reversing by block: %f seconds\n", cpu_time_used);

#else
    start_clock = clock();
    int out_descr = reverse_by_char(argv[1], argv[2]);
    if (out_descr == -1) {
        printf("Error when reversing file by one char\n");
        return -1;
    }
    end_clock = clock();

    cpu_time_used = ((double) (end_clock - start_clock)) / CLOCKS_PER_SEC;
    printf("Time taken reversing by one char: %f seconds\n", cpu_time_used);
    fprintf(fp, "Time taken reversing by one char: %f seconds\n", cpu_time_used);

#endif
    fprintf(fp, "\n");

    return 0;
}
