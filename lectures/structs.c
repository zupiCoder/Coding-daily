#include <stdio.h>
#include <stdlib.h>

struct tpoint {
    int x;
    int y;
};

struct oseba {
    char ime[30+1];
    char priimek[60+1];
    int starost;
    char emso[13+1];
};

//ko allocatas pomnilnik vedno sizeof(struct oseba);!!!

int main() {
    struct tpoint point;
    struct tpoint *ptrpoint = &point;

    ptrpoint->x = 17;
    point.y = 100;

    return 0;
}
