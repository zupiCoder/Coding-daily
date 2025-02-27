#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long rotateNum(long num) {
    long new_num = 0;

    while(num > 0) {
        long temp = num % 10; num = num / 10;

        new_num *= 10; new_num += temp;
    }
    return new_num;
}

bool isPalindrome(long num) {
    return rotateNum(num) == num;
}

bool isLychrel(long num, int k) {
    long temp = num;
    for(int i = 0; i < k; i++) {
        if((temp + rotateNum(temp) > pow(10,17)))return true;

        temp += rotateNum(temp);
        if(isPalindrome(temp)) return false;
    }
    return true;
}

int main() {

    int k = 0; int a = 0, b = 0;
    scanf("%d %d %d", &k, &a, &b);

    int counter = 0;

    for(int i = a; i <= b; i++) {
        if(isLychrel(i, k)) counter++;
    }

    printf("%d\n", counter);

    return 0;
}