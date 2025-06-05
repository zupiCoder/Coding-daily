#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "naloga2.h"

Ulomek sestej(Ulomek *a, Ulomek *b, int predznak);
Ulomek zmnozi(Ulomek *a, Ulomek *b);
int gcd(int a, int b);
void pokrajsaj(Ulomek *a);
int skupniImenovalec(int im_a, int im_b);

Ulomek sestej(Ulomek *a, Ulomek *b, int predznak) {
    Ulomek vsota;
    int st1 = a->st;
    int im1 = a->im;
    int st2 = b->st;
    int im2 = b->im;

    if (predznak == 1) st2 *= -1;

    int im = skupniImenovalec(im1, im2);
    st1 = st1 * (im / im1);
    st2 = st2 * (im / im2);

    vsota.st = st1 + st2;
    vsota.im = im;
    pokrajsaj(&vsota);

    return vsota;
}

Ulomek zmnozi(Ulomek *a, Ulomek *b) {
    Ulomek produkt;

    produkt.st = a->st * b->st;
    produkt.im = a->im * b->im;
    pokrajsaj(&produkt);
    return produkt;
}

Ulomek deli(Ulomek *a, Ulomek *b) {
    Ulomek rezultat;
    rezultat.st = a->st * b->im;
    rezultat.im = a->im * b->st;
    pokrajsaj(&rezultat);
    return rezultat;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void pokrajsaj(Ulomek *a) {

    if(a->im < 0) {
        a->im *= -1;
        a->st *= -1;
    }

    if(a->st == 0){
        a->im = 1;
    } else {
        int d = gcd(abs(a->st), abs(a->im));
        a->st /= d;
        a->im /= d;
    }
}

int skupniImenovalec(int im_a, int im_b) {
    return im_a * im_b;
}

Tocka projekcija(Tocka t, Premica p) {
    Ulomek x_p, y_p;

    if(p.navpicna) {
        x_p = p.n;
        y_p = t.y;
    } else if(p.k.st == 0) {
        x_p = t.x;
        y_p = p.n;
    } else {
        Ulomek min_one = {-1 , 1};
        Ulomek k_p = deli(&min_one, &p.k);

        Ulomek k_p_x = zmnozi(&k_p, &t.x);

        Ulomek n = sestej(&t.y, &k_p_x, 1);

        Ulomek n_diff = sestej(&n, &p.n, 1);
        Ulomek k_diff = sestej(&p.k, &k_p, 1);

        x_p = deli(&n_diff, &k_diff);
        Ulomek kx = zmnozi(&p.k, &x_p);
        y_p = sestej(&kx, &p.n, 0);
    }
    pokrajsaj(&x_p); pokrajsaj(&y_p);

    return (Tocka) {x_p, y_p};
}