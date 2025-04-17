#include <stdio.h>
#include <stdlib.h>

int combos(int n, int k) {
    if(n == 0) {
        printf("\n");
        return 1;
    }
    if(n < 0 || k <= 0) return 0;

    printf(" %d +", k);

    return combos(n-k, k) + combos(n, k-1);
}
    
int main() {

    int n = 0, k = 0;

    scanf("%d %d", &n, &k);
    int sum = combos(n, k);

    printf("[%d]\n", sum);

    return 0;
}