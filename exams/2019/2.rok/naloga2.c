#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "naloga2.h"

void izpisi(Oseba **osebe, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("{\"%s\", %d}\n", osebe[i]->ime, osebe[i]->starost);
    }
    printf("\n");
}

void uredi(Oseba **osebe, int n)
{

    for (int i = 0; i < (n - 1); i++)
    {
        bool sorted = true;
        for (int ix = 0; ix < (n - 1); ix++)
        {
            Oseba *current = osebe[ix];
            Oseba *next = osebe[ix + 1];

            int cmp = strcmp(current->ime, next->ime);

            if (cmp > 0)
            {
                Oseba *temp = next;
                osebe[ix + 1] = current;
                osebe[ix] = temp;
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}

void urediInsertionSort(Oseba **osebe, int n)
{
    for (int i = 1; i < n; i++)
    {
        Oseba *current = osebe[i];
        int sortedIdx = i - 1;

        while(sortedIdx >= 0 && strcmp(osebe[sortedIdx]->ime, current->ime) > 0) {
            osebe[sortedIdx + 1] = osebe[sortedIdx];
            sortedIdx--;
        }

        osebe[sortedIdx + 1] = current;
    }
}

int main()
{
    int n = 6;

    Oseba oseba1 = {"Bojan", 30};
    Oseba oseba2 = {"Ana", 25};
    Oseba oseba3 = {"Bojan", 40};
    Oseba oseba4 = {"Cene", 15};
    Oseba oseba5 = {"Bojan", 20};
    Oseba oseba6 = {"Ana", 20};

    Oseba *tabela[] = {&oseba1, &oseba2, &oseba3, &oseba4, &oseba5, &oseba6};

    printf("Pred ureditvijo:\n");
    izpisi(tabela, n);

    urediInsertionSort(tabela, n);

    printf("Po ureditvi:\n");
    izpisi(tabela, n);

    return 0;
}