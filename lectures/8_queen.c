#include <stdio.h>
#include <stdlib.h>
//na koliko nacinov lahko postavimo 8 kraljic na sahovsko desko
//kam postavimo kraljice
//...
/*
    1) kraljice postavljam po stolpcih od leve proti desni
    2) ne vem kam v stolpcu naj postavim kraljico
    3) poskusim vse se dovoljene moznosti, grem samo v desno-> gledam nazaj katera polja so prepovedana
*/

/*
    int qs[8]l //indeks = stolpec, vrednost = vrstica
    ali se q1 in q2 napadata
    (q1 == q2) || (qs[q1] == qs[q2]) || (abs(q1-q2) == abs(qs[q1] - qs[q2])), pogoj da se q1 in q2 napadata

    na 8 nacinov postavim damo v prvi stolpec, nato klicem rekurzijo da postavim 7 dam v preostalih 7 stolpcev brez da se napadajo
    ce se dame napadajo potem return- base case;
*/

int main() {


    return 0;
}