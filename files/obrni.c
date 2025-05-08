#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void read_file(FILE* vhod, FILE* izhod, char *buffer) {
    char *temp = buffer;
    int remaining_size = MAX_SIZE;

    while(fgets(temp, remaining_size, vhod)) {
        int len = strlen(temp);
        temp += len;
        remaining_size -= len;
    }
}

void obrni(FILE* vhod, FILE* izhod) {
    
    char buffer[1000];
    read_file(vhod, izhod, buffer);

    int first_string = 0;
    size_t start_index = strlen(buffer) - 1;

    for(size_t index = start_index; index > 0; index--) {
        if(buffer[index - 1] == '\n') {
            char *temp = (buffer + index);
            fputs(temp, izhod);

            if(first_string == 0) {
                first_string = 1;
                fputc('\n', izhod);
            }

            buffer[index] = '\0';
        }
    }
    fputs(buffer, izhod);
}

int main(int argc, char *argv[]) {

    FILE* vhod = fopen(argv[1], "r");
    FILE* izhod = fopen(argv[2], "w");

    obrni(vhod, izhod);

    return 0;
}