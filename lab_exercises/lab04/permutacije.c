#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {

    int n = 0;
    scanf("%d", &n);

    bool permutation = true;

    for(int i = 0; i < n; i++) {
        int input = 0;
        scanf("%d", &input);

        if(input >= n) permutation = false;
    }

    if(permutation) {
        printf("DA\n");
    } else{
        printf("NE\n");
    }
    
    return 0;
}