#include <stdio.h>
#include <stdlib.h>
//izpisi velikost obrocka, ki ga prestavljamo
//izpis stanja obrockov pri premiku
//4 stolpci -> min stevilo premikov

void hanoi(int n, char t1, char t2, char t3) {
    if(n == 1) {
        printf("%c => %c\n", t1, t3);
    } else {
        hanoi(n-1, t1, t3, t2);
        printf("%c => %c\n",t1,t3);
        hanoi(n-1, t2, t1, t3);
    }
}

int main() {
    hanoi(4, 'a', 'b', 'c');

    return 0;
}