#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ftw.h>

long long total_files_size = 0;


int file_information(const char *path, const struct stat *sb, int type)
{
    if (!S_ISDIR(sb->st_mode)) {
        printf("%ld bytes: \t\t %-20s\n", sb->st_size, path);
        total_files_size += sb->st_size;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Pass only one directory as argument\n");
    }

    if (ftw(argv[1], file_information, 10) == -1) {
        printf("Error when browsing directory\n");
    }

    printf("----------------------------------\n");
    printf("%d bytes total\n", total_files_size);
    printf("----------------------------------\n");

    return 0;
}
