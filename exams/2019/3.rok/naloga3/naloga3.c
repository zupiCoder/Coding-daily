#include <stdio.h>
#include <stdlib.h>

int rekurz(int *arr, int n, int temp, int k1, int k2, int s)
{
    if (temp < 0)
        return 0;

    if (temp >= n)
        return 0;

    if (s < 0)
        return 0;

    if(arr[temp]) return 0;
    else arr[temp] = 1;

    int counter = 1;

    counter += rekurz(arr, n, temp - k1, k1, k2, s - 1);
    counter += rekurz(arr, n, temp - k2, k1, k2, s - 1);
    counter += rekurz(arr, n, temp + k1, k1, k2, s - 1);
    counter += rekurz(arr, n, temp + k2, k1, k2, s - 1);
    
    return counter;
}

int main()
{

    int n, k1, k2, s;
    scanf("%d %d %d %d", &n, &k1, &k2, &s);

    int *arr = calloc(n, sizeof(int));

    int count = rekurz(arr, n, 0, k1, k2, s);
    printf("%d\n", count);

    free(arr);

    return 0;
}