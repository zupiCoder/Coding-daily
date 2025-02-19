#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int findCombinations(int n, int m, int a, int b) {
    
    int sum = 0; int count = 0;
    if(n == 0) return 1;

    for(int i = 1; i <= a; i++) {
        for(int j = b; j > i && j >= m; j--) {
            int temp_sum = sum + i*j;

            if (temp_sum <= n) {
                count += findCombinations(n - temp_sum, m, n, n);
            }
        }
    }      
    return count;
}

int main() {

    int n = 0; int m = 0;

    scanf("%d", &n); scanf("%d", &m);

    int total = findCombinations(n, m, n, n);

    printf("%d\n", total);

    return 0;
}
