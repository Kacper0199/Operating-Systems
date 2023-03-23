#include "ex1.h"
#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 128


MemoryBlockArray *init_memory_block_array(int max_size){
        MemoryBlockArray *array = (MemoryBlockArray *) malloc(sizeof(MemoryBlockArray));
        array->max_size = max_size;
        array->current_size = 0;
        array->blocks = (void **) calloc(max_size, sizeof(void *));

        return array;
}

void count_in_file(MemoryBlockArray *array, const char *filename){
    char command[BUFF_SIZE];
    sprintf(command, "wc %s > /tmp/count.tmp", filename);
    system(command);

    FILE *count_file = fopen("/tmp/count.tmp", "r");
    if (count_file == NULL){
        return ;
    }

    char buffer[BUFF_SIZE];
    if (fgets(buffer, BUFF_SIZE, count_file) == NULL){
        fclose(count_file);
        return ;
    }

    char *buff;
    long file_size;

    fseek(count_file, 0, SEEK_END);
    file_size = ftell(count_file);
    fseek(count_file, 0, SEEK_SET);

    buff = malloc(file_size*sizeof(char));

    if (buff){
        fread(buff, sizeof(char), file_size, count_file);
    }

    fclose(count_file);

    array->blocks[array->current_size] = calloc(file_size-1, sizeof(char));
    memmove(array->blocks[array->current_size], buff, (file_size-1)*sizeof(char));

    array->current_size++;
    remove("/tmp/count.tmp");
}



void *get_block(MemoryBlockArray *memory, int index){
    if (index < 0 || index >= memory->max_size){
        return NULL;
    }
    else{
        return memory->blocks[index];
    }
}


void remove_block(MemoryBlockArray *memory, int index) {
    if (index < 0 || index >= memory->max_size){
        return;
    }
    else{
        free(memory->blocks[index]);
        memory->blocks[index] = NULL;
    }
}


void free_memory(MemoryBlockArray *memory){
    if (memory == NULL) {
        return;
    }
    else{
        for (int i=0; i < memory->max_size; i++){
            if (memory->blocks[i] != NULL){
                free(memory->blocks[i]);
            }
        }
        free(memory->blocks);
    }
}
