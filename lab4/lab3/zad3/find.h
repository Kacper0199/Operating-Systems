#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>

#define STACK_SIZE 512


struct dir_struct{
    char path[PATH_MAX]; 
    DIR *dirpath; 
};

void read_file(const char *path, const char *pattern);
int handle_dots(struct dirent *dp);
void find(const char *directory_path, const char *pattern);
