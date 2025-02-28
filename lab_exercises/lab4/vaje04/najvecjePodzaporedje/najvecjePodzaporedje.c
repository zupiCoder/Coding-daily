#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
    
int main() {

    int n = 0;
    scanf("%d", &n);

    int max_sum = INT_MIN; int temp_sum = 0;
    
    for(int i = 0; i < n; i++) {
        int input = 0; scanf("%d", &input);
        temp_sum += input;

        if(temp_sum > max_sum) max_sum = temp_sum;
        if(temp_sum < 0) temp_sum = 0;        
    }

    printf("%d\n", max_sum);

    return 0;
}