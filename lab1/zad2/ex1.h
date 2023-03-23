#ifndef ex1_h
#define ex1_h
#include <stdlib.h>


typedef struct {
	void **blocks;
	int max_size;
	int current_size;

} MemoryBlockArray;


MemoryBlockArray *init_memory_block_array(int max_size);
void count_in_file(MemoryBlockArray *array, const char *filename);
void *get_block(MemoryBlockArray *memory, int index);
void remove_block(MemoryBlockArray *memory, int index);
void free_memory(MemoryBlockArray *memory);

#endif
