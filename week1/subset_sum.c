//week1: day5 subset sum equals k
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool subarray_sum(int t[], int n, int k, int i) {

    if(i == n) return false;

    int j = i;
    int temp = 0;
    while(temp < k) {
        if(j == n - 1) break;
        temp += t[j];
        j++;
    }

    if(temp == k) {
        return true;
    } else {
        return subset_sum(t, n, k, i + 1);
    }
}

int main() {

    int n = 0;
    int k = 0;

    scanf("%d %d", &n, &k);

    int *t = (int *) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    printf("%d\n", subset_sum(t, n, k, 0));

    return 0;
}