#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define start 0
#define decimal 1
#define binary 2
#define octal 3
#define mid 4
#define mid2 6
#define hexa 5

#define VALID_STATE '1'
#define INVALID_STATE '0'

int decimal_fun(char input) {
    return (input >= '0' && input <= '9') ? decimal : -1;
}

int binary_fun(char input) {
    return (input == '1' || input == '0') ? binary : -1;
}

int octal_fun(char input) {
    return (input >= '0' && input <= '7') ? octal : -1;
}

int hexa_fun(char input) {
    return ((input >= '0' && input <= '9') || (input >= 'A' && input <= 'F')) ? hexa : -1;
}

void printState(int state) {
    putchar((state == -1 || state == mid) ? INVALID_STATE : VALID_STATE);
}

int getState(char* input) {
    int state = -1;
    if (*input == '0') {
        state = octal;
        *input = getchar();
        if (*input == ' ' || *input == '\n') {
            printState(octal);
            state = start;
        } else if (*input == 'x') {
            state = mid;
        } else if (*input == 'b') {
            state = mid2;
        } else {
            state = octal_fun(*input);
        }
    } else {
        state = decimal_fun(*input);
    }
    return state;
}

int main() {
    char input = getchar();
    int state = getState(&input);

    while (input != '\n') {
        input = getchar();

        if (state == start) {
            state = getState(&input);
            continue;
        }

        if (input == ' ' || input == '\n') {
            printState(state);
            state = start;
            continue;
        }

        switch (state) {
            case decimal:
                state = decimal_fun(input);
                break;
            case octal:
                state = octal_fun(input);
                break;
            case hexa:
            case mid:
                state = hexa_fun(input);
                break;
            case mid2:
                state = binary_fun(input);
                break;
            case binary:
                state = binary_fun(input);
                break;
        }
    }
    putchar('\n');

    return 0;
}