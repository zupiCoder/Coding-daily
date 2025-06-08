#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    write coins recursive function,
    write coins iterative function
    exam ahh naloga
    izpisi vse moznosti ? DN
*/

unsigned long long coins(int cs[], unsigned long long memo[][8], int value, int i) {
    if(value == 0) return 1;

    if(value < 0 || i < 0) return 0;

    if(memo[value][i] != -1) return memo[value][i];

    unsigned long long count = 0;
    count += coins(cs, memo, value, i-1);
    count += coins(cs, memo, value - cs[i], i);

    memo[value][i] = count;
    return memo[value][i];
}

int main() {
    int value;
    scanf("%d", &value);

    unsigned long long memo[value+1][8];
    for(int i = 0; i <= value; i++) {
        for(int j = 0; j < 8; j++) memo[i][j] = -1;
    }

    int cs[] = {1, 5, 10, 20, 50, 100, 200, 500};

    int count = coins(cs, memo, value, 7);
    printf("%d\n", count);
    return 0;
}