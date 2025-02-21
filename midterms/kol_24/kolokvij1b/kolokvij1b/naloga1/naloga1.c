#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int temp = 0; bool up = true;

    for(int i = 0; i < n; i++) {
        int d = 0;
        scanf("%d", &d);

        for(int j = 0; j < d; j++) {
            if(j == d -1) break;

            printf("%d\n", temp);
            if(up) {
                temp++;
            } else if(!up) temp--;
        }
        up = !up;

    }
    printf("%d\n", temp);

    return 0;
}
