#include "find.h"


int main(int argc, char *argv[]){
    char *directory_path;
    char *pattern = argv[2];

    if (argc == 3){
        directory_path = argv[1];
    }
    else{
        printf("Pass two arguments - directory path and text to find at the beginning\n");
    }

    find(directory_path, pattern);

    return 0;
}
