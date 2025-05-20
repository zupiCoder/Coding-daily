#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recurse(char temp[], char c, char c1, char c2, int ix, int n) { 
    if(ix == n || c > c2) return;

    temp[ix] = c;

    for(int x = 0; x <= ix; x++) printf("%c", temp[x]);
    printf("\n");

    recurse(temp, c1, c1,  c2, ix + 1, n);
    recurse(temp, c+1, c1, c2, ix, n);
}

int main() {

    int n = 0;
    char c1 , c2;

    scanf("%d %c %c", &n, &c1, &c2);

    char* temp = (char*) malloc(n * sizeof(char));

    recurse(temp, c1, c1, c2,  0, n);

    return 0;
}