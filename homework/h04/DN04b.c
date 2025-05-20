#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main() {
    int n = 0, k = 0; 
    scanf("%d %d", &n, &k);

    long long unsigned counter = 0; int max = 0; int min = INT_MAX;
    int *arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    int freqLength = max - min + 1;
    int *frequences = calloc(freqLength, sizeof(int));

    for(int i = 0; i < n; i++) frequences[arr[i]-min]++;

    for(int i = 0; i < n; i++) {
        int ai = arr[i];
        int aj = k - ai;

        if(aj < ai) break;

        if(ai == aj) {
            counter += (long long) (frequences[ai - min] * (frequences[ai - min] - 1))/2;

        } else counter += (long long) frequences[ai - min] * frequences[aj - min];

        i += (frequences[ai - min] - 1);
    }    

    printf("%llu\n", counter);

    free(arr);
    free(frequences);
    return 0;
}