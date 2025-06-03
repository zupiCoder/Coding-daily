#include <stdio.h>
#include <stdlib.h>

void sets(int *arr, int *temp, int n, int indx, int i)
{
    if (i == n)
    {
        printf("{");

        if (temp[0] != -1)
        {
            printf("%d", temp[0]);

            for (int x = 1; x < indx; x++)
            {
                printf(", %d", temp[x]);
            }
        }

        printf("}\n");

        return;
    }

    sets(arr, temp , n, indx, i + 1);

    temp[indx] = arr[i];
    sets(arr, temp, n, indx + 1, i + 1);
    temp[indx] = -1;

}

int main()
{

    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        temp[i] = -1;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sets(arr, temp, n, 0, 0);

    return 0;
}