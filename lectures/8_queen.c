#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int solve_n_queens(int n);
int queens(int *qs, int n, int j);

// na koliko nacinov lahko postavimo 8 kraljic na sahovsko desko
// kam postavimo kraljice
//...
/*
    1) kraljice postavljam po stolpcih od leve proti desni
    2) ne vem kam v stolpcu naj postavim kraljico
    3) poskusim vse se dovoljene moznosti, grem samo v desno-> gledam nazaj katera polja so prepovedana
*/

/*
    int qs[8]; //indeks = stolpec, vrednost = vrstica
    ali se q1 in q2 napadata
    (q1 == q2) || (qs[q1] == qs[q2]) || (abs(q1-q2) == abs(qs[q1] - qs[q2])), pogoj da se q1 in q2 napadata

    na 8 nacinov postavim damo v prvi stolpec, nato klicem rekurzijo da postavim 7 dam v preostalih 7 stolpcev brez da se napadajo
    ce se dame napadajo potem return- base case;
*/

void run_tests() {
    // Base cases
    assert(solve_n_queens(1) == 1);  // 1 queen = 1 way
    assert(solve_n_queens(2) == 0);  // No valid arrangements
    assert(solve_n_queens(3) == 0);  // No valid arrangements

    // Classic test cases
    assert(solve_n_queens(4) == 2);  // 4 queens = 2 solutions
    assert(solve_n_queens(5) == 10);
    assert(solve_n_queens(6) == 4);
    assert(solve_n_queens(7) == 40);
    assert(solve_n_queens(8) == 92); // Classic 8-queens problem

    printf("All test cases passed!\n");
}

int solve_n_queens(int n)
{

    int *qs = calloc(n, sizeof(int));

    int count = queens(qs, n, 0);

    return count;
}

int abs(int a)
{
    return (a >= 0) ? a : a * -1;
}

int queens(int *qs, int n, int col)
{
    int count = 0;

    if(col == n) return 1;

    for(int ix = 0; ix < n; ix++)
    {
        bool safe = true;
        int try_row = ix;
        
        for(int prev_col = 0; prev_col < col; prev_col++)
        {
            if(qs[prev_col] == try_row || abs(prev_col - col) == abs(qs[prev_col] - try_row)) safe = false;
        }

        if(!safe) continue;

        qs[col] = try_row;
        count += queens(qs, n, col + 1);
    }
    return count;
}

int main()
{
    run_tests();
    return 0;
}