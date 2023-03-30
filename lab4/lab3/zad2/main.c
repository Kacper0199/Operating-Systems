#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Pass only one argument - directory\n");
    }

    setbuf(stdout, NULL);

    printf("%s ", argv[0]);

    fflush(stdout);
    execl("/bin/ls", "ls", argv[1], NULL);
    
    return 0;
}
