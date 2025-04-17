#include <stdio.h>
#include <stdlib.h>

void combos(int n, int k, int *arr, int i);

int main() {

    int n,k;
    scanf("%d %d", &n, &k);

    int *arr = (int *)malloc(n * sizeof(int));

    combos(n, k, arr, 0);

    return 0;
}

void combos(int n, int k, int *arr, int i) {
    if(n == 0) {
        printf("%d", arr[0]);
        for(int ind = 1; ind < i; ind++) printf(" + %d", arr[ind]);
        printf("\n");
        return;
    }
    if(n < 0 || k <= 0) return;

    arr[i] = k;

    combos(n-k, k, arr, i+1);
    combos(n, k-1, arr, i);
}