//week 1: day1 exercise/ recursive function

//test if it works
//how it works...
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_max(int *arr, int size) {
    int max_sum = INT_MIN;

    for(int i = 0; i < size; i++) {
        int temp_sum = 0;
        for(int j = i; j < size; j++) {
            temp_sum += arr[j];
            if (temp_sum > max_sum) {
                max_sum = temp_sum;
            }
        }
    }

    return max_sum;
}

//how this works ?
int find_max_recursive(int *arr, int n, int i, int temp_sum, int max_sum) {

    if (i == n) return max_sum;

    temp_sum += arr[i];

    if(temp_sum > max_sum) max_sum = temp_sum;

    if (temp_sum < 0) temp_sum = 0;
    
    return find_max_recursive(arr, n, i + 1, temp_sum, max_sum);
}

//best iterative algorithm ?

int main() {
        
    int n = 0;
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int m = find_max(arr, n);
    int mm = find_max_recursive(arr, n, 0, 0, INT_MIN);

    printf("%d\n", mm);

    free(arr);
    return 0;
}