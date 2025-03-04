#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define start 0
#define decimal 1
#define binary 2
#define octal 3
#define mid 4
#define hexa 5

#define VALID_STATE '1'
#define INVALID_STATE '0'

int decimal_fun(char input) {
    if(input >= '0' && input <= '9') return decimal;

    return -1;
}

int binary_fun(char input) {
    if(input == '1' || input == '0') return binary;

    return -1;
}

int octal_fun(char input) {
    if(input >= '0' && input <= '7') return octal;

    return -1;
}

int hexa_fun(char input) {
    if((input >= '0' && input <= '9') || (input >= 'A' && input <= 'F')) return hexa;

    return -1;
}

void printState(int state) {
    if(state == -1 || state == mid) {
        putchar(INVALID_STATE);
    } else putchar(VALID_STATE);
}            

int getState(char input) {
    int state = -1;
    if(input == '0') {
        state = octal;
        input = getchar();

        if(input == ' ' || input == '\n') {
            printState(octal);
            state = start;
        } else if(input == 'x') {
            state = mid;
        } else if(input == 'b') {
            state = mid;
        } else {
            state = octal_fun(input);
        }
    } else state = decimal_fun(input);

    return state;
}

int main() {
    
    char input = getchar(); //0
    int state = getState(input);

    while(input != '\n') {
        input = getchar();

        if(state == start) {
            state = getState(input);
            continue;
        }

        if(input == ' ' || input == '\n') {
            printState(state);
            state = start;
            continue;
        }

        if(state == decimal) {
            state = decimal_fun(input);
        } else if(state == octal) {
            state = octal_fun(input);
        } else if(state == hexa || state == mid) {
            state = hexa_fun(input);
        } else if(state == binary || state == mid) state = binary_fun(input);
    }
    putchar('\n');

    return 0;
}