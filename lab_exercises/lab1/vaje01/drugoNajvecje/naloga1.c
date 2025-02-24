#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {

    int n = getchar() - '0';
    getchar();

    int max1 = 0; int max2 = 0;

    for(int i = 0; i < n; i++) {
        int input = getchar() - '0';
        getchar();
        
        if(input > max1) {
            max2 = max1;
            max1 = input;
        } else if(input > max2) {
            max2 = input;
        } else if(input == max1) max2 = max1;
    }

    putchar(max2 + '0');
    putchar('\n');

    return 0;
}