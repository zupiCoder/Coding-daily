#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int x[] = {0, 0, 1, -1};
int y[] = {-1, 1, 0, 0};

bool visited(bool **visited, int i, int j) {
    return visited[i][j];
}

bool exist(char** board, int boardSize, int* boardColSize, int row, int col, char* word) {

    if(*word == '\0') return true;

    for(int k = 0; k < 4; k++) {
        int newRow = row + x[k];
        int newCol = col + y[k];
        if(newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardColSize[row]) {
            if(board[newRow][newCol] == *word) {
                return exist(board, boardSize, boardColSize, newRow, newCol, word + 1);
            } 
        }
    }

    return false;
}


//test1 test2 test 3 ..... coddinggggg

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    char **board = (char **) calloc(m, sizeof(char *));

    for(int i = 0; i < m; i++) {
        board[i] = (char *) calloc(n, sizeof(char));
        for(int j = 0; j < n; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    char word[16];
    for(int i = 0; i < 20; i++) {
        scanf("%c", &word[i]);
        if(word[i] == '\0') break;
    }

    bool flag = false;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(board[i][j] == word[0]) {
                flag = exist(board, m, &n, i, j, word);
            }
        }
    }

    printf("%d\n", flag);

    return 0;
}