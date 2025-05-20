#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void razbitja(int arr[], int take[], int **sets, int n, int sum, int k, int k_init, int i, int j, int tempSum) {
    if (k == 0) {
        bool valid = true;
        for (int i = 1; i < k_init; i++) {
            if (sets[i][0] < sets[i - 1][0]) {
                valid = false;
                break;
            }
        }
        if (!valid) return;
        
        printf("{");
        for(int ix = 0; ix < k_init; ix++) {
            if(ix > 0) printf(", {");
            if(ix == 0) printf("{");
            printf("%d", sets[ix][0]);
            for(int x = 1; sets[ix][x] != 0; x++) printf(", %d", sets[ix][x]);
            printf("}");
        }
        printf("}\n");
        return;
    }
    
    if(tempSum == sum) {
        sort(sets[k-1], j);
        razbitja(arr, take, sets, n, sum, k - 1, k_init, 0, 0, 0);
        return;
    }

    if(tempSum + arr[i] > sum) return;

    if(tempSum > sum) return;
    if(i == n) return;
    
    razbitja(arr, take, sets, n, sum, k, k_init, i + 1, j, tempSum);
    
    if(take[i] == 0) {
        take[i] = 1;
        sets[k-1][j] = arr[i];
        razbitja(arr, take, sets, n, sum, k, k_init, i + 1, j + 1, tempSum + arr[i]);
        //backtracking
        /*
            Every time we get out of recursion, we set the current element to 0, because we already printed/it was incorrect
            take[i] = 0, we undo it, as if we didnt take the element yet
        */
        sets[k-1][j] = 0;
        take[i] = 0;
    }
}

int main() {
    
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    int sum = 0;

    int* arr = (int *) malloc(n * sizeof(int));
    int* take = (int *) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int** sets = (int **) malloc(k * sizeof(int*));
    for(int i = 0; i < k; i++) sets[i] = (int *) calloc(n, sizeof(int));

    sum = sum / k;

    razbitja(arr, take, sets, n, sum, k, k, 0, 0, 0);

    return 0;
}