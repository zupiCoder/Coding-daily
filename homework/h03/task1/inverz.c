#include <stdbool.h>
#include <stdio.h>

#include "inverz.h"

long inverz(long y, long a, long b) {

    if(a > b) return -1;

    long mid = (a + b)/2;

    if(f(mid) > y) {
        return inverz(y, a, mid-1);
    } else if(f(mid) < y) {
        return inverz(y, mid+1, b);
    }

    return mid;
}