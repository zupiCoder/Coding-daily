#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define q0 0  //starting
#define q1 1  //final
#define q2 2  //predznak
#define q3 3  //final

int q1_fun(char input) {
    if(input >= '0' && input <= '9') return q1;

    return -1;
}

int q2_fun(char input) {
    if(input >= '1' && input <= '9') return q1;

    if(input == '0') return q3;

    return -1;
}

int q3_fun() {
    return -1;
}

void printState(int state) {
    if(state == q1 || state == q3) {
        putchar('1');
    } else putchar('0');
}

int getState(char input) {

    if(input == '+' || input == '-') return q2;

    if(input == '0') return q3;

    return q1;
}

int main() {

    char input = getchar();
    int state = getState(input);

    while(input != '\n') {
        input = getchar();

        if(input == ' ' || input == '\n') {
            printState(state);
            state = q0;
            continue;
        }

        if(state == q0) {
            state = getState(input);
            continue;
        }

        if(state == q1){
            state = q1_fun(input);
        } else if(state == q2) {
            state = q2_fun(input);
        } else if(state == q3) {
            state = q3_fun();
        } 
    }
    putchar('\n');

    return 0;
}