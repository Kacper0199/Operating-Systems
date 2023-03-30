#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void signal_info(int num, siginfo_t *info, void *context){

    printf("signal num: %d from PPID %d\n", num, info->si_pid);
    printf("signal info: \n");
    printf("-sig int: %d\n", info->si_int);
    printf("-sig type: %d\n", info->si_code);
    printf("-sig status: %d\n", info->si_status);

    if (info->si_code != SI_QUEUE){
        printf("kill signal sent\n");
    }
    else{
        printf("queue signal sent\n");
    }

    // SIGUSR1
    if (num == 10){
        printf("signal: SIGUSR1\n");
    }
    // SIGINT
    else if (num == 2){
        printf("signal: SIGINT\n");
    }
    else{
        printf("other signal\n");
    }
}


int main(){
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = signal_info;

    int sigaction_num = sigaction(SIGUSR1, &action, NULL);

    if (sigaction_num < 0){
        printf("sigaction error");
        return -1;
    }

    pid_t pid = getpid();
    printf("Current PID: %d\n", pid);


    int kill_num = kill(pid, SIGUSR1);
    if (kill_num == -1){
        printf("kill error");
        return -1;
    }

    return 0;
}
