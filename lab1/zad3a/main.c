#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>
#include "ex1.h"

#define MAX_COMMAND_LENGTH 128


void print_time(double system_time, double user_time, double real_time)
{
    printf("Time taken - System: %f seconds, User: %f seconds, Real: %f seconds\n", system_time, user_time, real_time);
}

int main()
{

    #ifdef DYN

    void *hndl = dlopen("./libex1_dyn.so", RTLD_LAZY);
    
    if(hndl == NULL){
        printf("Cannot open libex1_dyn.so\n");
        return -1;
    }

    MemoryBlockArray (*init_memory_block_array)(int);
    void (*count_in_file)(MemoryBlockArray *, char *);
    void (*get_block)(MemoryBlockArray *, int);
    void (*remove_block)(MemoryBlockArray *, int);
    void (*free_memory)(MemoryBlockArray *);

    init_memory_block_array = (MemoryBlockArray (*)(int)) dlsym(hndl, "init_memory_block_array");
    count_in_file = (void (*)(MemoryBlockArray *, char *)) dlsym(hndl, "count_in_file");
    get_block = (void (*)(MemoryBlockArray *, int)) dlsym(hndl, "get_block");
    remove_block = (void (*)(MemoryBlockArray *, int)) dlsym(hndl, "remove_block");
    free_memory = (void (*)(MemoryBlockArray *)) dlsym(hndl, "free_memory");

    #endif

    char command[MAX_COMMAND_LENGTH];
    char *token;
    MemoryBlockArray *array = NULL;
    time_t system_start, system_end;
    clock_t user_start, user_end;
    struct timeval real_start, real_end;

    while (1)
    {
        printf(">>");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        token = strtok(command, " \n");

        if (strcmp(token, "init") == 0)
        {
            token = strtok(NULL, " \n");
            int size = atoi(token);
            time(&system_start);
            user_start = clock();
            gettimeofday(&real_start, NULL);
            array = init_memory_block_array(size);
            gettimeofday(&real_end, NULL);
            user_end = clock();
            time(&system_end);
        }
        else if (strcmp(token, "count") == 0)
        {
            token = strtok(NULL, " \n");
            const char *filename = token;
            time(&system_start);
            user_start = clock();
            gettimeofday(&real_start, NULL);
            count_in_file(array, filename);
            gettimeofday(&real_end, NULL);
            user_end = clock();
            time(&system_end);
        }
        else if (strcmp(token, "show") == 0)
        {
            token = strtok(NULL, " \n");
            int index = atoi(token);
            time(&system_start);
            user_start = clock();
            gettimeofday(&real_start, NULL);
            void *block = get_block(array, index);
            gettimeofday(&real_end, NULL);
            user_end = clock();
            time(&system_end);
            printf("Block contents:\n%s\n", (char *)block);
        }
        else if (strcmp(token, "delete") == 0)
        {
            token = strtok(NULL, " \n");
            int index = atoi(token);
            time(&system_start);
            user_start = clock();
            gettimeofday(&real_start, NULL);
            remove_block(array, index);
            gettimeofday(&real_end, NULL);
            user_end = clock();
            time(&system_end);
        }
        else if (strcmp(token, "destroy") == 0)
        {
            time(&system_start);
            user_start = clock();
            gettimeofday(&real_start, NULL);
            free_memory(array);
            gettimeofday(&real_end, NULL);
            user_end = clock();
            time(&system_end);
            break;
        }
        else
        {
            printf("Unknown command.\n");
        }

        double system_time = difftime(system_end, system_start);
        double user_time = (double)(user_end - user_start) / CLOCKS_PER_SEC;
        double real_time = (double)(real_end.tv_sec - real_start.tv_sec) + (double)(real_end.tv_usec - real_start.tv_usec) / 1000000;
  
        print_time(system_time, user_time, real_time);
    }

    #ifdef DYN
    dlclose(hndl);
    #endif

    return 0;
}
