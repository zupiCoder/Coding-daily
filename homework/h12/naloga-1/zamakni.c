#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1001

int main(int argc, char *argv[]) {
    int z = 0;
    char buffer[MAX_SIZE];
    char fixed[MAX_SIZE];
    /*
        \n ni terminator kot '\0', pazi!
    */
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    while(fgets(buffer, MAX_SIZE, input)) {
        int ix = 0; int temp = 0;

        if(strlen(fixed) >= 2 && fixed[strlen(fixed) -1] == '\n' && fixed[strlen(fixed)-2] == '{') z+= 4;

        while(buffer[ix] == ' ') ix++;

        if(buffer[ix] == '}') {
            if(z < 4) z = 0;
            else z -= 4;
        }

        while(temp < z) {
            fixed[temp] = ' ';
            temp++;
        }

        strcpy(fixed + temp, buffer + ix);
        fputs(fixed, output);
    }
    fclose(input);
    fclose(output);

    return 0;
}