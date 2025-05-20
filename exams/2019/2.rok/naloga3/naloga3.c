#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void dfs_helper(int arr[][4], int path[], bool visited[][30], int m, int n);
void dfs(int arr[][4], int path[], bool visited[][30], int m, int n, int i, int j, int steps);

void dfs_helper(int arr[][4], int path[], bool visited[][30], int m, int n)
{
    dfs(arr, path, visited, m, n, 0, 0, 0);
}

void dfs(int arr[][4], int path[], bool visited[][30], int m, int n, int i, int j, int steps)
{
    if (i == (m - 1) && (j == n - 1))
    {
        for (size_t ix = 0; ix < steps; ix++)
        {
            printf("%d", path[ix]);
        }
        printf("\n");
        return;
    }

    // st. vrstice v kateri smo(koliko stolpcev smo skippali) + index stolpca v katerem smo
    visited[i][j] = true;
    int index = i * n + j;

    for (int dir = 0; dir < 4; dir++)
    {
        int ni = i + (dir == 3) - (dir == 1);
        int nj = j + (dir == 2) - (dir == 0);

        if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

        if(arr[index][dir] == 0 && !visited[ni][nj])
        {
            path[steps] = dir;
            dfs(arr, path, visited, m, n, ni, nj, steps + 1);
        }
    }
    visited[i][j] = false;
}

int main()
{
    int m, n;
    scanf("%d %d\n", &m, &n);

    int SIZE = m * n;

    int arr[SIZE][4];
    int path[SIZE];
    bool visited[30][30] = {false};
    int minSteps = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int ix = 0; ix < 4; ix++)
        {
            int num = getchar() - '0';
            arr[i][ix] = num;
        }
        getchar();
    }

    dfs_helper(arr, path, visited, m, n);

    return 0;
}