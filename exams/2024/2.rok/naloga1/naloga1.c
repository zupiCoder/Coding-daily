#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int abs(int a) {
    return a >= 0 ? a : (a * -1);
}

int main(int argc, char *argv[]) {

    char* inputName = argv[1];
    char* outputName = argv[2];

    FILE* input = fopen(inputName, "r");
    FILE* output = fopen(outputName, "w");

    int n = 0;
    int p = 0;

    fscanf(input, "%d %d\n", &n, &p);

    char buffer[500];
    bool movements[8];
    for(int i = 0; i < 8; i++) movements[i] = false;

    for(int x = 0; x < p; x++){

        if(fgets(buffer, 500, input) == NULL) break;

        buffer[strlen(buffer)] = '\0';

        bool safe = true;
        char prev_col = buffer[0];
        int prev_row = buffer[1] - '0';

        for(int i = 3; i < (strlen(buffer) -2); i+=3) {
            char col = buffer[i];
            int row = buffer[i+1] - '0';

            int delta_col = col - prev_col;
            int delta_row = row - prev_row;

            if(abs(delta_col) * abs(delta_row) != 2) safe = false;

            if(delta_col == 2 && delta_row == 1){
                movements[0] = true;
            } else if(delta_col == 2 && delta_row == -1){
                movements[1] = true;
            } else if(delta_col == -2 && delta_row == 1){
                movements[2] = true;
            } else if(delta_col == -2 && delta_row == -1){
                movements[3] = true;
            } else if(delta_col == 1 && delta_row == 2){
                movements[4] = true;
            } else if(delta_col == 1 && delta_row == -2){
                movements[5] = true;
            } else if(delta_col == -1 && delta_row == 2){
                movements[6] = true;
            } else if(delta_col == -1 && delta_row == -2){
                movements[7] = true;
            }

            prev_col = col;
            prev_row = row;
        }

        for(int k = 0; k < 8; k++) {
            if(movements[k] == false) safe = false;
            movements[k] = false;
        }

        fprintf(output, "%d", safe);
        if(x < (p-1)) fprintf(output,"\n");
    }

    return 0;
}