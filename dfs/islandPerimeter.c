#include <stdlib.h>
#include <stdbool.h>

int dfs(int** grid, int gridSize, int* gridColSize, int i, int j);

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j]) {
                return dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
}
int directions[][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int** grid, int gridSize, int* gridColSize, int i, int j) {
    int perimeter = 0;

    if((i < 0 || i >= gridSize) || (j < 0 || j >= gridColSize[i])) return 0;

    if(grid[i][j] == 0) return 1;
    if(grid[i][j] == -1) return 0;

    grid[i][j] = -1;

    for(int indx = 0; indx < 4; indx++) {
        int x = i + directions[indx][0];
        int y = j + directions[indx][1];

        if((x < 0 || x >= gridSize) || (y < 0 || y >= gridColSize[i])) {
            perimeter++; continue;
        }
        perimeter += dfs(grid, gridSize, gridColSize, x, y);
    }
    return perimeter;
}