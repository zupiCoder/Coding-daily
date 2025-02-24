//week1: day3 transpose a matrix using a recursive function
#include <stdio.h>
#include <stdlib.h>

void transpose(int **t, int n, int m, int i, int j) {

    if(i == (n - 1) && j == (m - 1)) return;

    int temp = t[j][i];

    t[j][i] =  t[i][j];
    t[i][j] = temp;

    if(j + 1 < m) {
        transpose(t, n, m, i, j + 1);
    } else if(j == m - 1) {
        if(i < n - 1)
        i++;
        transpose(t, n, m, i, i);
    }

    return;
}

//+ + + +
//+ * * + 
//+ * * +
//+ + + +

//write a recursive rotate function
void rotate_90(int **t, int n, int m, int i, int j, int counter, int l, int temp) {

    if(counter == l) return;

    int temp = t[j][n - i - 1];
    t[j][n - i - 1] = t[i][j];


    if(j + 1 < m) {
        
    }

}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    int **t = (int **) calloc(n, sizeof(int *));

    for(int i = 0; i < n; i++) {
        t[i] = (int *) calloc(m,sizeof(int));

        for(int j = 0; j < m; j++) {
            scanf("%d", &t[i][j]);
        }
    }

    int l = min(n, m) / 2;

    transpose(t, n, m, 0, 0);

    printMatrix(t, n, m);

    for (int i = 0; i < n; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}