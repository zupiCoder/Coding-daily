//week1: day4 find peak element in array using binary search
#include <stdio.h>
#include <stdlib.h>

int find_peak(int *t, int n, int lo, int hi, int max) {

    int m = (lo + hi)/ 2;

    if(m == 0) {
        if(t[0] > t[1]) {
            if(t[m] > max) return t[m];

            return max;
        }
    }

    if(m == n - 1) {
        if(t[m] > t[m - 1]) {
            if(t[m] > max) return t[m];

            return max;
        }
    }

    if(t[m] > t[m - 1] && t[m] > t[m + 1]) return t[m];

    if(t[m] < t[m + 1]) {
        int temp = find_peak(t, n, m + 1, hi, max);
        if(temp > max) max = temp;
        return max;
    } else if(t[m] > t[m + 1]) {
        int temp = find_peak(t, n, m + 1, hi, max);
        if(temp > max) max = temp;
        return max;
    }

    return -1;
}   

int main() {

int n = 0;
scanf("%d", &n);

int *t = (int *) calloc(n, sizeof(int));

for(int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
}

    int peak = find_peak(t, n, 0, n - 1, -1);

    printf("%d\n", peak);

    return 0;
}