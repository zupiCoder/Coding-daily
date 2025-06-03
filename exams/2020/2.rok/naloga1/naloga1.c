#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void odstraniDuplikate(FILE* vhod, FILE* izhod) {
    
    char buffer, prev;
    prev = fgetc(vhod);
    fputc(prev, izhod);
    buffer = fgetc(vhod);

    while(buffer != '\n') {

        if((buffer < 'A' || buffer > 'Z') && (buffer < 'a' || buffer > 'z')) fputc(buffer, izhod);
        else if(prev != buffer) fputc(buffer, izhod);

        prev = buffer;
        buffer = fgetc(vhod);
    }
}

void odstraniDupe(FILE* vhod, FILE* izhod) {

    char buffer, prev;
    fread(&prev, sizeof(char), 1, vhod);
    fwrite(&prev, sizeof(char), 1, izhod); 
    fread(&buffer, sizeof(char), 1, vhod);

    while(buffer != '\n') {
        
        if((buffer < 'A' || buffer > 'Z') && (buffer < 'a' || buffer > 'z')) fwrite(&buffer, sizeof(char), 1, izhod);
        else if(prev != buffer) fwrite(&buffer, sizeof(char), 1, izhod);

        prev = buffer;
        fread(&buffer, sizeof(char), 1, vhod);
    }
}

int main() {

    FILE* input = fopen("test01.txt", "r");
    FILE* output = fopen("test01.out", "w");

    odstraniDupe(input, output);

    return 0;
}