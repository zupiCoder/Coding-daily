#include <stdio.h>
#include <stdlib.h>
//v[i] - volumen i-tega predmeta
//c[i] - cena i-tega predmeta
int memo[1000][1000][11];//stores the maximum value you can get from i-th item to n-1-th item with the remaining capacity w

int knapsack(int V, int n, int* v, int* c, int k, int i) {
    if(i == n) return 0;
    
    int cena1 = 0, cena2 = 0;

    if(memo[i][V][k] != -1) return memo[i][V][k];

    if(V - v[i] >= 0) {
        if(v[i] % 2 != 0) {
            if(k > 0) {
                cena1 = c[i] + knapsack(V - v[i], n, v, c, k - 1, i + 1);
            }
        } else {
            cena1 = c[i] + knapsack(V - v[i], n, v, c, k, i + 1);
        }
    }
    cena2 = knapsack(V, n, v, c, k, i + 1);

    //calculate cena1 if we dont take the item && cena2 if we take the item, then write the maximum into memo[i][V] where V is our current capacity
    return memo[i][V][k] = cena1 > cena2 ? cena1 : cena2;
}

int main() {

    int V, n, k;
    scanf("%d\n%d\n%d", &V, &n, &k);

    int* v = calloc(n, sizeof(int));
    int* c = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            for(int k = 0; k < 11; k++) memo[i][j][k] = -1;
        }
    }
    int max = knapsack(V, n, v, c, k, 0);
    
    printf("%d\n", max);
    return 0;
}