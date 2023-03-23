#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Pass only one argument - number of processes\n");
        return -1;
    }

    int num_children_proc = atoi(argv[1]);
    for (int i = 0; i < num_children_proc; i++){
        pid_t pid = fork();

        if (pid == -1){
            perror("fork");
            return 1;
        } else if (pid == 0){
            printf("Parent PID: %d | Child PID: %d\n", getppid(), getpid());
            return 0;
        }
    }

    for (int i = 0; i < num_children_proc; i++){
        wait(NULL);
    }

    printf("%s\n", argv[1]);
    return 0;
}
