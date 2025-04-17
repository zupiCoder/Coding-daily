#include <stdio.h>
#include <stdlib.h>

int dfs(int** arr, int n, int i) {
    if(i == n) return 0;

    if(arr[i][0] == -1 && arr[i][1] == -1) return 1;

    
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

    int h = dfs();

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}