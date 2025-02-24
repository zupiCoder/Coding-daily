#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int findCombinations(int n, int m) {
    
    int count = 0;
    if(n == 0) return 1;

    for(int i = 1; i <= n; i++) {
        for(int j = n; j > i && j >= m; j--) {
            int temp_sum = i*j;

            if (temp_sum <= n) count += findCombinations(n - temp_sum, m);
        }
    }      
    return count;
}

int main() {

    int n = 0; int m = 0;

    scanf("%d", &n); scanf("%d", &m);

    int total = findCombinations(n, m);

    printf("%d\n", total);

    return 0;
}