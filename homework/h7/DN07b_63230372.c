#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void izpisi() {
    
}

int main() {

    int n = 0;
    scanf("%d", &n);
    getchar(); //NEWLINE TRAP, pazi ce uporabljas scanf in getchar()

    char** arr = (char**) malloc(n * sizeof(char*));

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

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < strlen(arr[i]); j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}