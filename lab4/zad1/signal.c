#include "signal.h"


void signal_view(int signal){
    printf("Get signal number: %d\n", signal);
}


void child_sig_sett(char *argg, sigset_t *sigset){

    int compare_pend = strcmp(argg, "pending");
    int compare_handl = strcmp(argg, "handler");
    int compare_ign = strcmp(argg, "ignore");
    int compare_mask = strcmp(argg, "mask");

    if (compare_pend == 0){
        sigpending(sigset);
        if (sigismember(sigset, SIGUSR1)){
            printf("Child is pending in parent\n");
        } else {
            printf("Child is not pending in parent\n");
        }
    }
    else if (compare_handl == 0){
        signal(SIGUSR1, signal_view);
    } 
    else if (compare_mask == 0){
        sigemptyset(sigset);
        sigaddset(sigset, SIGUSR1);
        sigprocmask(SIG_BLOCK, sigset, NULL);
    } 
    else if (compare_ign == 0){
        signal(SIGUSR1, SIG_IGN);
    } 
    else {
        printf("Pass only valid argument\n");
        return;
    }
}


void forking(char *argg, sigset_t *sigset, pid_t *pid){
    int status;
    int compare_pend = strcmp(argg, "pending");

    if (pid == 0){
        if (compare_pend == 0){
            sigpending(sigset);
            if (sigismember(sigset, SIGUSR1)){
                printf("Current signal is pending in child\n");
            } 
            else{
                printf("Current signal is not pending in child\n");
            }
        } 
        else{
            printf("Child signal send\n");
            raise(SIGUSR1);
        }
    } 
    else{
        wait(&status);

        if (WIFSIGNALED(status)){
            printf("Receiving from child\n");
        } 
        else{
            printf("Not receiving from child\n");
        }
    }
}
