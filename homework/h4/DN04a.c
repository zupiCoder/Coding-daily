#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int n = 0; 
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    int *arr2 = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++) scanf("%d", &arr2[i]);

    for (int k = 0; k < n; k++) {
        bool match = true;
        for (int i = 0; i < n; i++) {
            if (arr[(k + i) % n] != arr2[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            printf("%d\n", k);
            break;
        }
    }
    return 0;
}