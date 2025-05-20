#include <stdio.h>
#include <stdlib.h>

void sets(int *arr, int *temp, int sum, int i, int x, int n) {    
    if(sum < 0) return;

    if(sum == 0) {
        printf("{%d", temp[0]);
        for(int ix = 1; ix < i; ix++) printf(", %d", temp[ix]);
        printf("}\n");
        return;
    }
    if(x == n) return;

    temp[i] = arr[x];

    sets(arr, temp, sum - temp[i], i+1, x+1, n);
    sets(arr, temp, sum, i, x+1, n);
}

int main() {

    int n = 0;
    scanf("%d", &n);

    int* arr = (int *) malloc(n * sizeof(int));
    int* temp = (int *) malloc(n * sizeof(int));

    int sum = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sum = sum / 2;
    
    temp[0] = arr[0];
    sum -= temp[0];
    sets(arr, temp, sum, 1, 1, n);

    return 0;
}