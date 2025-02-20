#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int square = 0;
    int n = 0;
    scanf("%d", &n);

    int* t = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    for(int i = 0; i < n; i++) {
        int input = 0;
        scanf("%d", &input);
        square += (t[i] - input) * (t[i] - input);
    }

    printf("%d\n", square);

    return 0;
}
