#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*  
    -> create an array, each cell holds tens, hundreds, thousands digits
    -> we sum it up
    -> take care of carry-on
*/  
#define SIZE 200

int main() {

    int *t = calloc(SIZE, sizeof(int));
    t[SIZE-1] = 1;

    int carry = 0;
    for(int i = 2; i <= 100; i++) {
        
        for(int d = SIZE-1; d >= 0; d--) {
            t[d] *= i;
            t[d] += carry;

            int temp = t[d];

            t[d] = t[d] % 10;
            carry = temp / 10;
        }
    }

    int sum = 0;
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", t[i]);
        sum += t[i];
    }
    printf("\n");

    printf("%d\n", sum);

    return 0;
}