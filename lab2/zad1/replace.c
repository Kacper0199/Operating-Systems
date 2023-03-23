#include "replace.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 512


int replace_with_lib(char *input_file, char *output_file, char search_char, char replace_char) {
    FILE *in_file_pt;
    FILE *out_file_pt;

    in_file_pt = fopen(input_file, "rb");
    if (in_file_pt == NULL) {
        printf("Cannot open input file %s", input_file);
        return -1;
    }

    out_file_pt = fopen(output_file, "wb");
    if (out_file_pt == NULL) {
        printf("Cannot open output file %s", output_file);
        fclose(in_file_pt);
        return -1;
    }

    size_t num_elem_read;
    size_t num_elem_write;
    char buffer[BUFF_SIZE];

    while ((num_elem_read = fread(buffer, 1, BUFF_SIZE, in_file_pt)) > 0) {
        for (size_t i = 0; i < num_elem_read; i++) {
            if (buffer[i] == search_char) {
                buffer[i] = replace_char;
            }
        }

        num_elem_write = fwrite(buffer, 1, num_elem_read, out_file_pt);
        if (num_elem_write != num_elem_read) {
            printf("Cannot write to %s", output_file);
            fclose(in_file_pt);
            fclose(out_file_pt);
            return -1;
        }
    }

    fclose(in_file_pt);
    fclose(out_file_pt);

    return 0;
}


int replace_with_sys(char *input_file, char *output_file, char search_char, char replace_char) {
    int in_file;
    int out_file;

    in_file = open(input_file, O_RDONLY);
    if (in_file == -1) {
        printf("Cannot open input file %s", input_file);
        return -1;
    }

    out_file = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (out_file == -1) {
        printf("Cannot open output file %s", output_file);
        close(in_file);
        return -1;
    }

    ssize_t num_bytes_read;
    ssize_t num_bytes_write;
    char buffer[BUFF_SIZE];

    while ((num_bytes_read = read(in_file, buffer, BUFF_SIZE)) > 0) {
        for (ssize_t i = 0; i < num_bytes_read; i++) {
            if (buffer[i] == search_char) {
                buffer[i] = replace_char;
            }
        }

        num_bytes_write = write(out_file, buffer, num_bytes_read);
        if (num_bytes_write != num_bytes_read) {
            printf("Cannot write to %s", output_file);
            close(in_file);
            close(out_file);
            return -1;
        }
    }

    close(in_file);
    close(out_file);

    return 0;
}
