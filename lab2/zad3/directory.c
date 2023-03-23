#include "directory.h"
#include <stdio.h>
#include <string.h>


int save_files_stats(struct file_info *files, int *num_files) {
    DIR *dir;
    char *pwd = ".";
    struct dirent *dirent;
    struct stat buff;

    dir = opendir(pwd);
    if (dir == NULL) {
        printf("Cannot open current directory");
        return -1;
    }

    *num_files = 0;
    int file_stats;
    
    while ((dirent = readdir(dir)) != NULL) {

        file_stats = stat(dirent->d_name, &buff);
        if (file_stats == -1) {
            printf("Error with file stats");
            continue;
        }

        if (!S_ISDIR(buff.st_mode)) {
            strcpy(files[*num_files].filename, dirent->d_name);
            files[*num_files].size = buff.st_size;
            (*num_files)++;
        }
    }

    closedir(dir);

    return 0;
}

void print_stats(struct file_info file) {
    printf("%lld\t%s\n", file.size, file.filename);
}

long long files_total_size(struct file_info *files, int num_files) {
    long long total_size = 0;

    for (int i = 0; i < num_files; i++) {
        total_size += files[i].size;
    }

    return total_size;
}
