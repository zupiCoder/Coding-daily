#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int n = 0;

void vsote(int arr[], int index, int temp_n, int k, int a , int b) {

    if(temp_n == 0 && ((index) < a || (index) > b)) return;

    if(temp_n < 0 || k <= 0) return;

    if(temp_n == 0) {
        printf("%d", arr[index - 1]);
        for(int i = (index -2); i >= 0; i--) {
            printf("+%d", arr[i]);
        }
        printf("\n");
        return;
    }

    arr[index] = k;
    vsote(arr, index + 1, temp_n - k, k, a, b);
    vsote(arr, index, temp_n, k - 1, a, b);
}

int main() {

    int a, b;

    scanf("%d %d %d", &n, &a, &b);

    int arr[n];
    for(int i = 0; i < n; i++) arr[i] = -1;

    vsote(arr, 0, n, n, a, b);

    return 0;
}