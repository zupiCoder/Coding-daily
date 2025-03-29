#include <stdio.h>
#include <stdlib.h>
/*
    [Two pointer algorithm]
*/
int main() {

    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    long long counter = 0;

    int *arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int i = 0; int j = n-1; 
    while(i < j) {
        
        if(arr[i] + arr[j] == k) {
            if(arr[i] == arr[j]) {
                long long count = j - i + 1;
                counter += (count * (count - 1)) / 2;
                break;
            } else {
                int l_dup = 1;
                while(i + 1 < j && arr[i] == arr[i+1]) {
                    l_dup++; i++;
                }

                int r_dup = 1;
                while(j - 1 > i && arr[j] == arr[j-1]) {
                    r_dup++; j--;
                }

                counter += (long long) l_dup * r_dup;

                i++; j--;
            }
        } else if(arr[i] + arr[j] > k) j--;
        else i++;
    }
    printf("%lld\n", counter);

    return 0;
}