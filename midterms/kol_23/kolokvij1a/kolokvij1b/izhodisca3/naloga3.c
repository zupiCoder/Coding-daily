#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findCombinations(int n, int m, int temp_ai, int temp_bi) {

    int count = 0;
    if(n == 1) return 1;

    for(int bi = 0; bi <= n; bi++) {
        for(int ai = m; (ai > bi) && (ai + bi) <= m; ai--) {

            if(ai == temp_ai || bi == temp_bi) break;
            int temp = (ai + bi);

            if(temp <= n) {
                count += findCombinations(n/temp, m, ai, bi);
            }
        } 
    }             

    return count;
}

int main() {

    int n = 0; int m = 0;
    scanf("%d", &n); scanf("%d", &m);

    int total = findCombinations(n, m, -1, -1);

    printf("%d\n", total);

    return 0;
}
