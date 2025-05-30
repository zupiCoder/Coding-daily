#include <stdio.h>
#include <stdlib.h>

int dfs(int** arr, int n, int i) {
    if(i >= n) return 0;
    if(i == -1) return 0;

    if(arr[i][0] == -1 && arr[i][1] == -1) return 0;

    int l = 1 + dfs(arr, n, arr[i][0]);
    int d = 1 + dfs(arr, n, arr[i][1]);

    return l > d ? l : d;
}

int main() {

    int n;
    scanf("%d", &n);

    int** arr = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*) malloc(2 * sizeof(int));
    }

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    int h = dfs(arr, n, 0);

    printf("%d\n", h);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}