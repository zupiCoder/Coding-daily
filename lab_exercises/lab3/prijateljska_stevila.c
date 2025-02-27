#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int sumOfDividers(int num) {
    int counter = 1;
    for(int i = 2; i < num; i++) if(num % i == 0) counter += i;

    return counter;
}

int isFriendly(int num) {
    int temp = sumOfDividers(num);

    if(sumOfDividers(temp) == num) return temp;

    return -1;
}

int main() {

    int n = 0;
    scanf("%d", &n);

    int num = isFriendly(n);

    if(num == -1) {
        printf("NIMA\n");
    } else
    printf("%d\n", num);

    return 0;
}