#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {

    int n = getchar() - '0';
    getchar();

    int num = getchar() - '0';
    getchar();
    int returned = 1;

    for(int i =1; i < n; i++) {
        int temp = getchar() - '0';
        getchar();
        if(temp != num) {
            returned = 0;
            break;
        }
    }

    putchar(returned + '0');
    putchar('\n');

    return 0;
}