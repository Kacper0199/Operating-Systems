#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


void signal_view(int signal);
void child_sig_sett(char *argg, sigset_t *sigset);
void forking(char *argg, sigset_t *sigset, pid_t *pid);
