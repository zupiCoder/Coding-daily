#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {

    int v = 0; int s = 0;
    scanf("%d %d", &v, &s);

    int k =0;

    int** t = malloc(v * sizeof(int*));

    for(int i = 0; i < v; i++) {
        t[i] = malloc(s * sizeof(int));

        for(int j = 0; j < s; j++) {
            scanf("%d", &t[i][j]);

            if(t[i][j] != 0) k++;
        }
    }

    int temp = 0;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < s; j++) {
            if(t[i][j] != 0) {
                printf("%d", t[i][j]);
                temp++;
                if(temp < k)
                printf("_");
            }
        }
    }
    printf("\n");

    printf("%d", 0);

    int bi_prev = 0;
    for(int i = 0; i < v; i++) {
        int temp = 0;
        for(int j = 0; j < s; j++) {
            if(t[i][j] != 0) temp++;
        }
        int bi = bi_prev + temp; bi_prev = bi;
        printf("_%d", bi);
    }
    printf("\n");

    temp = 0;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < s; j++) {
            if(t[i][j] != 0) {
                printf("%d", j);
                temp++;
                if(temp < k)
                printf("_");
            }
        }
    }
    printf("\n");


    return 0;
}
