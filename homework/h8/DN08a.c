#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSorted(int *arr, int n) {
    for(int i = 1; i < n; i++) if(arr[i-1] > arr[i]) return false;
    return true;
}

void swap(int* arr, int i, int j, int r) {
    for (int k = 0; k < r; k++) {
        int temp = arr[i + k];
        arr[i + k] = arr[j + k];
        arr[j + k] = temp;
    }
}

int sort(int* arr, int n, int k, int r) {
    int count = 0;

    if(k == 0) return isSorted(arr, n);
    
    if (isSorted(arr, n)) count +=1;

    for(int i = 0; i <= (n-r); i++) {
        for(int j = (i+r); j <= (n-r); j++) {
            swap(arr, i, j, r);
            count += sort(arr, n, k-1, r);
            swap(arr, i, j, r);
        }
    }
    return count;
}

int main() {

    int n = 0, k = 0, r = 0;
    scanf("%d %d %d", &n, &k, &r);

    int *arr = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int count = sort(arr, n, k, r);

    printf("%d\n", count);

    return 0;
}