#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int readNum(int num, char input) {
    num = num * 10;
    num += input - '0';
    return num;
}

bool checkNeg(char input) {
    if(input == '-') return true;
    return false;
}

int numSize(int num) {
    int counter = 0; 
    if(num < 0) num *= -1;
    while(num > 0){
        num  = num / 10;
        counter++;
    }
    return counter;
}

void printNum(int num, int numSize) {
    int d = 1;
    for(int i = 0; i < (numSize-1); i++) d *= 10;

    if(num < 0) {
        putchar('-');
        num *= -1;
    }

    while(d >= 1) {
        int temp = num / d;
        num = num % d;
        putchar(temp + '0');
        d = d / 10;
    }
    putchar('\n');
}


int main() {

    int a = 0; int b = 0;
    bool neg = false;
    char input = getchar();

    neg = checkNeg(input);
    if(neg) input = getchar();

    while(input != ' ') {
        a = readNum(a, input);
        input = getchar();
    }
    if(neg) a *= -1;

    input = getchar();
    neg = checkNeg(input);
    if(neg) input = getchar();

    while(input != '\n') {
        b = readNum(b, input);
        input = getchar();
    }
    if(neg) b *= -1;

    printNum(a+b, numSize(a+b));

    return 0;
}