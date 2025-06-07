/*
Ro"cno testiranje (npr. za primer 01):

gcc naloga1.c
./a.out vhod01.pgm 150 izhod01.pgm
cmp izhod01.pgm ref01.pgm

Samodejno testiranje:

export name=naloga1
make test

Lahko si pomagate tudi s programom hexdump:

hexdump -C datoteka.pgm

Testni primeri:

01: primer iz besedila
02..07: vsaka pika je bodisi 0 bodisi 255
08..12: splo"sni primeri

Testne datoteke:

test*.par: argumenti ukazne vrstice
vhod*.pgm: vhodna slika
ref*.pgm: pri"cakovana izhodna slika
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {

    char *inputName = argv[1];
    int prag = atoi(argv[2]);
    char *outputName = argv[3];

    char temp[4];
    int max_val;

    FILE* input = fopen(inputName, "rb");
    FILE* output = fopen(outputName, "wb");

    fscanf(input, "%s\n", temp); //P5\n

    int width = 0, height = 0;
    fscanf(input, "%d %d\n", &width, &height);// w_h

    fscanf(input, "%d\n", &max_val);//255\n

    fprintf(output, "%s\n", temp);
    fprintf(output, "%d %d\n", width, height);
    fprintf(output, "%d\n", max_val);

    for(int i = 0; i < (width*height); i++) {
        unsigned char byte;
        unsigned char new_byte;
        fread(&byte, sizeof(unsigned char), 1, input);

        if(byte >= prag) {
            printf("%d >= %d\n", byte, prag);
            new_byte = 255;
        } else {
            printf("%d < %d\n", byte, prag);
            new_byte = 0;
        }
        printf("%d\n", new_byte);
        fwrite(&new_byte, sizeof(unsigned char), 1, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}