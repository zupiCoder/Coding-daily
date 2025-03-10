#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int collatz(long long n, int *memo) {
    if (n == 1) return 1;

    if (n < MAX && memo[n] != -1) return memo[n];

    int length = 0;
    if (n % 2 == 0) {
        length = collatz(n / 2, memo) + 1;
    } else length = collatz(3 * n + 1, memo) + 1;

    if (n < MAX) memo[n] = length;

    return length;
}

int findLargest(int *memo) {
    int maxLength = 0;
    int startingNumber = 0;

    for (int i = 1; i < MAX; i++) {
        int length = collatz(i, memo);
        if (length > maxLength) {
            maxLength = length;
            startingNumber = i;
        }
    }

    return startingNumber;
}

int main() {

    int *memo = malloc(MAX * sizeof(int));

    for (int i = 0; i < MAX; i++) memo[i] = -1;

    printf("%d\n", findLargest(memo));

    free(memo);

    return 0;
}