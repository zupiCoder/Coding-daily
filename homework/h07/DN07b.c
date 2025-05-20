#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void izpisi(char** arr, char* temp, int n, int i, int ix) {
    if(i == n) {
        for(int k = 0; k < ix; k++) printf("%c", temp[k]);
        printf("\n");
        return;
    }

    for(int j = 0; j < strlen(arr[i]); j++) {
        temp[ix] = arr[i][j];
        izpisi(arr, temp, n, i + 1, ix + 1);
    }
}

void izpisiHelper(char** arr, char* temp, int n) {
    izpisi(arr, temp, n, 0, 0);
}

int main() {

    int n = 0;
    scanf("%d", &n);
    getchar(); //NEWLINE TRAP, pazi ce uporabljas scanf in getchar()

    char** arr = (char**) malloc(n * sizeof(char*));
    char* temp = (char*) malloc((n+1) * sizeof(char));
    
    for(int i = 0; i < n; i++) arr[i] = malloc(43 * sizeof(char));
    
    for(int i = 0; i < n; i++) {
        int j = 0;
        char input = getchar();
        while(input != '\n') {
            arr[i][j] = input;
            j++;
            input = getchar();
        }
        arr[i][j] = '\0';
    }
    izpisiHelper(arr, temp, n);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}