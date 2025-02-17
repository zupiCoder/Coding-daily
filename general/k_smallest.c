//week 1: day2 exercise/ recursive function
#include <stdio.h>
#include <stdlib.h>

int partition(int *t, int low, int high) {
    int pivot = t[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (t[j] <= pivot) {
            i++;
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
        }
    }

    int temp = t[i + 1];
    t[i + 1] = t[high];
    t[high] = temp;

    return i + 1;
}

int quickselect(int *t, int low, int high, int k) {

    if(low == high) return t[low];

    int pivot = partition(t, low, high);

    if(pivot < k) {
        return quickselect(t, pivot + 1, high, k);
    } else if(pivot > k) {
        return quickselect(t, low, pivot - 1, k);
    } else if(pivot == k) return t[pivot];

}

int main() {

    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    int *t = (int *)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    int kth_smallest = quickselect(t, 0, n - 1, k - 1);

    printf("%d\n", kth_smallest);

    return 0;
}