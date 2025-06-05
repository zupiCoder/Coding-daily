#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 500

int abs(int a) {
    return a >= 0 ? a : a*(-1);
}

int main(int argc, char *argv[]) {

    char *inputName = argv[1];
    char *outputName = argv[2];

    FILE* input = fopen(inputName, "r");
    FILE* output = fopen(outputName, "w");

    int n = 0;
    int p = 0;
    fscanf(input, "%d %d\n", &n, &p);

    char buffer[MAX_SIZE];

    bool **board = malloc((n+1) * sizeof(bool*));
    for(int i = 0; i <= n; i++) {
        board[i] = malloc((n+1) * sizeof(bool));
        for(int j = 0; j <= n; j++) {
            board[i][j] = false;
        }
    }   

    for(int x = 0; x < p; x++) {

        fgets(buffer, MAX_SIZE, input);

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                board[i][j] = false;
            }  
        }

        bool safe = true;
        int prev_col = (buffer[0] - 'a') + 1;
        int prev_row = buffer[1] - '0';

        board[prev_col][prev_row] = true;

        for(int i = 3; i < strlen(buffer)-2; i+=3) {

            int col = (buffer[i] - 'a') + 1;
            int row = buffer[i+1] -'0';

            if(board[col][row]) safe = false;
            
            int dif_col = abs(col - prev_col);
            int dif_row = abs(row - prev_row);

            int dif_value = dif_col * dif_row;

            if(dif_value != 2) safe = false;

            prev_col = col;
            prev_row = row;

            board[prev_col][prev_row] = true;
        }
        int visited = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i][j]) visited++;
            }
        }
        if(visited != n * n) safe = false;

        fprintf(output, "%d\n", safe);
    }

    for(int i = 0; i <= n; i++) free(board[i]);
    free(board);

    fclose(input);
    fclose(output);

    return 0;
}