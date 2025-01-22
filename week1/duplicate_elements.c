//week1: day4 remove duplicates using double pointer
#include <stdio.h>
#include <stdlib.h>
//poglej kako se passajo pointerji funkcijam in zakaj uporabljamo double pointer namesto single pointerja!!!!

void remove_duplicates(int *t, int n, int *lo, int *hi) {

    if(lo == &t[n - 1] && hi == &t[n - 1]) return;

    while(*hi == *lo && hi < &t[n]) hi++;

    int *temp = lo + 1;
    int dif = hi - lo;

    while(temp != &t[n - 1]) {
        int *e = (temp + dif);
        int el = *(temp + dif);
        *e = -1;
        *temp = el;
        temp++;
    }
    if(lo + 1 < &t[n -1]) remove_duplicates(t, n, lo + 1, lo + 1);
}

int resize_array(int *t, int n, int **pp) {

    int temp = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(t[i] != -1) break;
        temp++;
    }

    int *p = (int *) calloc(n, sizeof(n - temp));

    for(int i = 0; i < (n - temp); i++) {
        p[i] = t[i];
    }
    *pp = p;

    return n - temp;
}


int main() {

    int n = 0;
    scanf("%d", &n);

    int *t = (int *) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    int *temp = t;

    remove_duplicates(t, n, temp, temp);

    int *resized = NULL;
    int resize = resize_array(t, n, &resized);

    printf("%p\n", resized);

    for(int i = 0; i < resize; i++) {
        printf("%d ", t[i]);
        printf("\n");
    }

    free(t);
    free(resized);

    return 0;
}