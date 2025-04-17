#include <stdio.h>
#include <stdlib.h>
//v[i] - volumen i-tega predmeta
//c[i] - cena i-tega predmeta
int memo[2000][2000];//stores the maximum value you can get from i-th item to n-1-th item with the remaining capacity w

int knapsack(int V, int n, int* v, int* c, int i) {
    if(i == n) return 0;
    
    int cena1 = 0, cena2 = 0;

    if(memo[i][V] != -1) return memo[i][V];

    if(V - v[i] >= 0)
    cena1 = c[i] + knapsack(V - v[i], n, v, c, i + 1);
    cena2 = knapsack(V, n, v, c, i + 1);

    //calculate cena1 if we dont take the item && cena2 if we take the item, then write the maximum into memo[i][V] where V is our current capacity
    return memo[i][V] = cena1 > cena2 ? cena1 : cena2;
}

int main() {

    int V = 0, n = 0;
    scanf("%d\n%d", &V, &n);

    int* v = calloc(n, sizeof(int));
    int* c = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);

    for(int i = 0; i < 2000; i++) {
        for(int j = 0; j < 2000; j++) memo[i][j] = -1;
    }
    int max = knapsack(V, n, v, c, 0);

    printf("%d\n", max);
    return 0;
}