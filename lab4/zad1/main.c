#include "signal.h"


int main(int argc, char **argv){
    sigset_t sigset;

    if (argc != 2){
        printf("Select only one argument : \n-ignore\n-handler\n-mask\n-pending\n");
        return -1;
    }

    child_sig_sett(argv[1], &sigset);
    printf("Signal send\n");
    raise(SIGUSR1);

    pid_t pid = fork();
    if (pid < 0){
        printf("Error when forking\n");
        return -1;
    }

    forking(argv[1], &sigset, &pid);


    int compare_ign = strcmp(argv[1], "ignore");
    int compare_mask = strcmp(argv[1], "mask");
    int compare_pend = strcmp(argv[1], "pending");

    if (compare_ign == 0){
        execlp(argv[0], argv[0], "ignore", NULL);
    } 
    else if (compare_mask == 0){
        execlp(argv[0], argv[0], "mask", NULL);
    } 
    else if (compare_pend == 0){
        execlp(argv[0], argv[0], "pending", NULL);
    }

    return 0;
}
