#include "reverse.h"


int reverse_by_char(char* input_file, char* output_file) {
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

    fseek(in_file_pt, 0, SEEK_END);
    long file_size = ftell(in_file_pt);
    fseek(in_file_pt, -1, SEEK_CUR);

    char end;
    fread(&end, 1, 1, in_file_pt);
    fseek(in_file_pt, -2, SEEK_CUR);

    for (long i = file_size-2; i >= 0; i--) {
        char c;
        fread(&c, 1, 1, in_file_pt);

        fwrite(&c, 1, 1, out_file_pt);

        fseek(in_file_pt, -2, SEEK_CUR);
    }

    fwrite(&end, 1, 1, out_file_pt);

    fclose(in_file_pt);
    fclose(out_file_pt);

    return 0;
}


int reverse_by_block(char* input_file, char* output_file) {
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


    char buffer[BUFF_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFF_SIZE, in_file_pt)) > 0) {
        for (int i = 0; i < bytes_read / 2; i++) {
            char temp = buffer[i];
            buffer[i] = buffer[bytes_read - i - 2];
            buffer[bytes_read - i - 2] = temp;
        }

        fwrite(buffer, sizeof(char), bytes_read, out_file_pt);
    }

    fclose(in_file_pt);
    fclose(out_file_pt);

    return 0;
}
