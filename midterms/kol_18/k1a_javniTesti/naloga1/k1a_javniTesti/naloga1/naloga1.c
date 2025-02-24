#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXIMUM 1000000

int main() {
    int n = 0; 
    scanf("%d", &n);

    int* t = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    int* first = malloc(MAXIMUM * sizeof(int));
    int* last = malloc(MAXIMUM * sizeof(int));

    for(int i = 0; i < MAXIMUM; i++) {
        first[i] = -1; last[i] = -1;
    }

    for(int i = 0; i < n; i++) {

        if(first[abs(t[i])] == -1)
        first[abs(t[i])] = i;

        last[abs(t[i])] = i;
    }
    int d = 0; int dist = 0;

    for(int i= 0; i < MAXIMUM; i++) {
        if(first[i] != -1)
        dist = last[i] - first[i];

        if(dist > d) d = dist;
    }
    printf("%d\n", d);

    if(d == 0) return 0;

    for(int i = 0; i < n; i++) {
        if(first[abs(t[i])] == i && (last[abs(t[i])] - first[abs(t[i])] == d)) 
        printf("%d\n", t[i]);
    }

    free(t);
    free(first);
    free(last);

    return 0;
}
