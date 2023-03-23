#include "replace.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]) {

    if (argc != 5) {
        printf("Wrong number of arguments");
        return -1;
    }

    FILE *fp = fopen("pomiar_zad_1.txt", "a+");
    char search_char = argv[1][0];
    char replace_char = argv[2][0];

    clock_t start_clock; 
    clock_t end_clock;
    double cpu_time_used;

#ifdef LIB
    start_clock = clock();
    int out_descr = replace_with_lib(argv[3], argv[4], search_char, replace_char);
    if (out_descr == -1) {
        printf("Error when replacing char using lib\n");
        return -1;
    }
    end_clock = clock();

    cpu_time_used = ((double) (end_clock - start_clock)) / CLOCKS_PER_SEC;
    printf("Time taken using lib: %f seconds\n", cpu_time_used);
    fprintf(fp, "Time taken using lib: %f seconds\n", cpu_time_used);

#else
    start_clock = clock();
    int out_descr = replace_with_sys(argv[3], argv[4], search_char, replace_char);
    if (out_descr == -1) {
        printf("Error when replacing char using sys\n");
        return -1;
    }
    end_clock = clock();
    
    cpu_time_used = ((double) (end_clock - start_clock)) / CLOCKS_PER_SEC;
    printf("Time taken using sys: %f seconds\n", cpu_time_used);
    fprintf(fp, "Time taken using sys: %f seconds\n", cpu_time_used);

#endif
    fprintf(fp, "\n");

    return 0;
}
