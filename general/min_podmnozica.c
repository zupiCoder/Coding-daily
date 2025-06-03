#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int subsets(int arr[], bool take[], int n, int i) {
    if(i == n) {
        int first_set = 0;
        int second_set = 0;

        for(int ix = 0; ix < n; ix++) {
            if(take[ix]) first_set += arr[ix];
            else second_set += arr[ix];
        }
        int dif = first_set - second_set;
        if(dif < 0) dif = dif * -1;

        return dif;
    }

    take[i] = true;
    int get = subsets(arr, take, n, i+1);
    take[i] = false;
    int skip = subsets(arr, take, n, i+1);
   
    return get > skip ? skip : get;
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    bool take[n];

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++) take[i] = false;

    int res = subsets(arr, take, n, 0);

    printf("[%d]\n", res);

    return 0;
}