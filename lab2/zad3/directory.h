#include <dirent.h>
#include <sys/stat.h>

#define NAME_LEN 512


struct file_info {
    char filename[NAME_LEN];
    long long size;
};

int save_files_stats(struct file_info *files, int *num_files);
void print_stats(struct file_info file);
long long files_total_size(struct file_info *files, int num_files);
