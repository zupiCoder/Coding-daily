#include <stdbool.h>
#include <stdio.h>

#include "tranzitivnost.h"

int tranzitivnost(int a, int b) {

    bool transitive = true;
    bool antiTransitive = true;
    
    for(int x = a; x <= b; x++) {
        for(int y = a; y <= b; y++) {
            for(int z = a; z <= b; z++) {
                if(f(x,y) && f(y,z) && !f(x,z)) transitive = false;
                if(f(x,y) && f(y,z) && f(x,z)) antiTransitive = false;
            }
        }
    }

    if(transitive && antiTransitive) return 1;
    if(transitive) return 2;
    if(antiTransitive) return 3;

    return 4;
}