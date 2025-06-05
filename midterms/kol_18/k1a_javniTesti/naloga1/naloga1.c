#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {

    int n = 0; 
    scanf("%d", &n);

    int* t = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    int d = 0;
    
    for(int i = 0; i < n; i++) {
        int j = (n - 1) - i;
        if(t[i] == t[j]) {
            if(abs(j - i) > d)
            d = abs(j - i);
        }
    }
    
    printf("%d\n", d);

    if(d == 0) return 0;

    for(int i = 0; i < n; i++) {
        if(i + d < n && t[i] == t[i+d]) printf("%d\n", t[i]); 
    }   

    return 0;
}
