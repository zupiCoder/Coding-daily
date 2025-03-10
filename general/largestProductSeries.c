#include <stdio.h>
#include <stdlib.h>

#define Size 13

void moveLeft(int *arr) {

    for(int i = 1; i < Size; i++) arr[i-1] = arr[i];
}

long long productOfArray(int *arr) {
    long long product = 1;
    for(int i = 0; i < Size; i++) product *= arr[i];

    return product;
}

void copyArr(int *dest, int *src) {
    for(int i = 0; i < Size; i++) {
        dest[i] = src[i];
    }
}

int main() {

    int *arr = (int *) malloc(Size * sizeof(int));
    int *tempArr = (int *) malloc(Size * sizeof(int));
    for(int i = 0; i < Size; i++) {
        arr[i] = 1;
        tempArr[i] = 1;
    }

    long long res = 0;

    for(int i = 0; i < 1000; i++) {
        char c = getchar();
        if(c < '0' || c > '9') continue;
        int input = c - '0';

        moveLeft(tempArr);
        tempArr[Size-1] = input;

        long long temp = productOfArray(tempArr);

        if(temp > res) {
            res = temp;
            copyArr(arr, tempArr);
        }
    }

    printf("%lli\n", res);

    return 0;
}