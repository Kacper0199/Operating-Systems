#include "find.h"


void read_file(const char *path, const char *pattern){
    int filedir;
    filedir = open(path, O_RDONLY);
    if (filedir == -1){
        perror("open");
        return;
    }

    char buffer[PATH_MAX];
    ssize_t num_read = read(filedir, buffer, PATH_MAX);
    if (num_read == -1){
        perror("read");
        close(filedir);
        return;
    }

    int cmp = strncmp(buffer, pattern, strlen(pattern));
    if (cmp == 0){
        printf("%s %ld\n", path, (long)getpid());
    }

    close(filedir);
}


int handle_dots(struct dirent *dp){
    if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
        return 0;
    }
    return -1;
}


void find(const char *directory_path, const char *pattern){
    DIR *dirpath;
    dirpath = opendir(directory_path);
    if (dirpath == NULL){
        perror("opendir");
        return;
    }
    char path[PATH_MAX];

    struct dirent *dp;
    struct dir_struct stack[STACK_SIZE];
    struct dir_struct *top = stack;

    top->dirpath = dirpath;
    strncpy(top->path, directory_path, PATH_MAX);

    while (top >= stack){
        dirpath = top->dirpath;

        if ((dp = readdir(dirpath)) != NULL){
            if (handle_dots(dp) == 0){
                continue;
            }

            int len;
            if (len >= PATH_MAX) {
                printf("Too long path name\n");
                continue;
            }

            if (strcmp(top->path, "/") == 0){
                len = snprintf(path, PATH_MAX, "/%s", dp->d_name);
            } else {
                len = snprintf(path, PATH_MAX, "%s/%s", top->path, dp->d_name);
            }
            

            struct stat path_stat;
            int status = stat(path, &path_stat);
            if (status != 0){
                perror("stat");
                exit(EXIT_FAILURE);
            }

            if (S_ISDIR(path_stat.st_mode)){
                DIR *subdir = opendir(path);
                if (subdir == NULL) {
                    perror("opendir");
                    continue;
                }
                
                top++;
                top->dirpath = subdir;
                strncpy(top->path, path, PATH_MAX);

            } else{
                read_file(path, pattern);
            }

        }else{
            closedir(dirpath);
            top--;
        }
    }
}
