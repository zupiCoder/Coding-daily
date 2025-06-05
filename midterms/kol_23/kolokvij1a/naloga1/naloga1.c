#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n = 0; bool found = false;
    scanf("%d", &n);

    int* t = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]); 
    }

    int* p1 = t;
    int sum = 0;

    for(int i = n -1; i >= 0; i--) {
        if(*p1 != t[i]) {
            found = true;
        }
        sum +=t[i];
        p1++;
    }

    if(found) {
        printf("NE\n");
    } else printf("DA\n");

    printf("%d\n", sum);

    return 0;
}
