#include "directory.h"
#include <stdio.h>

#define FILES_NUM 50


int main() {
    struct file_info files[FILES_NUM];
    int num_file;
    long long total_size;

    save_files_stats(files, &num_file);

    for (int i = 0; i < num_file; i++) {
        print_stats(files[i]);
    }

    total_size = files_total_size(files, num_file);
    printf("%lld\ttotal\n", total_size);

    return 0;
}
