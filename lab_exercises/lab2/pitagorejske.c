#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int m = 0; int n = 0;

    scanf("%d %d", &m, &n);
    int counter = 0;

    for(int c = m; c <= n; c++) {

        for(int a = 1; a < c; a++) {
            for(int b = a; b < c; b++) {
                if(a*a + b*b == c*c) counter++;
            }
        }
    }

    printf("%d\n", counter);

    return 0;
}