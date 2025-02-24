#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int prev = 0;
    scanf("%d", &prev);

    int d = 0; int dir = 1;

    for(int i = 1; i < n; i++) {
        int curr = 0; scanf("%d", &curr);
        d++;

        if((dir && prev > curr) || (!dir && prev < curr)) {
            printf("%d\n", d);
            d = 1;
            dir = !dir;
        }
        prev = curr;
    }
    printf("%d\n", d + 1);
    return 0;
}
