#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char path[n + 1];

    scanf("%s", path);

    int max = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (path[i] == 'G')
            temp++;
        else
            temp--;

        if (temp > max)
            max = temp;
    }

    char outputArr[max][n + 1];

    for (int i = 0; i < max; i++)
        for (int j = 0; j < n; j++)
            outputArr[i][j] = 0;

    int temp_j = max - 1;

    for (int i = 0; i < n; i++)
    {
        if (path[i] == 'G')
        {
            outputArr[temp_j][i] = '/';
            temp_j--;
        }
        else if (path[i] == 'D')
        {
            outputArr[temp_j + 1][i] = '\\';
            temp_j++;
        }
    }

    for (int j = 0; j < max; j++)
    {
        for (int i = 0; i < (n); i++)
        {
            if (outputArr[j][i] != '\\' && outputArr[j][i] != '/')
                outputArr[j][i] = '.';
            printf("%c", outputArr[j][i]);
        }
        printf("\n");
    }

    return 0;
}