#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int a = 0;
int b = 0;

void razbitja(int ind[][2], char niz[], int start_index, int end_index, int k) {

    if(end_index == strlen(niz) && (k < a || k > b)) return;
    
    if(start_index > strlen(niz) || end_index > strlen(niz)) return;

    if(end_index == strlen(niz) && start_index == strlen(niz)) {

        for(int ix = 0; ix < k; ix++) {
            if(ix > 0) printf("|");
            for(int x = ind[ix][0]; x <= ind[ix][1]; x++) printf("%c", niz[x]);
        }
            printf("\n");
            return;
    }

    ind[k][0] = start_index;
    ind[k][1] = end_index;

    razbitja(ind, niz, end_index + 1, end_index + 1, k + 1);

    razbitja(ind, niz, start_index, end_index + 1, k);
}

int main() {
    char niz[20];
    
    scanf("%s", niz);
    scanf("%d %d", &a, &b);

    int ind[50][2];
    int start_index = 0;
    int end_index = 0;

    int len = strlen(niz);

    razbitja(ind, niz, start_index, end_index, 0);

    return 0;
}