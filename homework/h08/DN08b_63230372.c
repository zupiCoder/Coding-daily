#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool recurse(int n, int k, int i) {
    if(n == 0) {
        if(i % 2 == 0) return true;
        return false;
    }

    if(i % 2 != 0) {
        for(int ix = 1; ix <= k; ix++) {
            if(!recurse(n - ix, k, i+1)) return false;
        }
        return true;
    }
}

void coins(int *arr, int n, int k, int i) {

    if(n == 0) {
        if(i % 2 != 0) {
            printf("CRNI\n");
            return;
        }

        printf("%d ", arr[0]);
        for(int ix = 0; ix <= i; ix++) {
            if(ix % 2 == 0) printf("-> [%d]", arr[ix]);
            if(ix % 2 != 0) printf("-> %d", arr[ix]);
        }
        printf("\n");
        return;
    }

    if(n < 0) return;

    for(int x = 1; x <= k; x++) {
        arr[i] = x;
        coins(arr, n - x, k, i + 1);
    }
}

int main() {

    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    int* arr = (int *) malloc(n * sizeof(int));

    //coins(arr, n, k , 0);

    for(int x = 1; x <= k; x++) {
        bool stat = recurse(8, x, 1);
        printf("[%d]:STAT\n", stat);
    }
    
    return 0;
}