#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    
    int counter = 0; bool zeros = true;
    char input = getchar();

    while(input == '0') input = getchar();
    
    while(input != '\n') {
        counter++;
        input = getchar();
        if(input == '1') zeros = false;
    }
    counter--;

    if(zeros) printNum(counter, numSize(counter));
    if(!zeros) printNum(counter+1, numSize(counter+1));

    return 0;
}