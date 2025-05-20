#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {

    int a = 0; int b = 0;
    scanf("%d %d", &a, &b);

    int input = 0;
    scanf("%d", &input);

    int min = a; int max =b;

    while(input != 0) {
        
        if(input == 1) {
            min = (min + max)/2 + 1;
        } else if(input == -1) {
            max = (min + max)/2 - 1;
        }
        scanf("%d", &input);
    }

    if(max == min) {
        printf("%d\n", max);
    } else if(max < min || min > max) {
        printf("PROTISLOVJE\n");
    } else if(max != min) {
        printf("%d ", min); printf("%d\n", max);
    }

    return 0;
}