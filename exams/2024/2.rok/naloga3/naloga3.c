#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void dfs(int tree[][2], int node, int k, int h) {

    if(node == 0) return;

    if(h == k) {
        printf("%d\n", node);
        return;
    }

    dfs(tree, tree[node][0], k, h+1);
    dfs(tree, tree[node][1], k, h+1);
}

int main() {

    int n = 0;
    int k = 0;
    char* fileName = malloc(22 * sizeof(char));

    scanf("%s", fileName);
    scanf("%d %d", &n, &k);

    FILE* input = fopen(fileName, "rb");

    int tree[n+1][2];

    for(int node = 1; node <= n; node++) {
        unsigned char left_child;
        unsigned char right_child;
        fread(&left_child, 1, 1, input);
        fread(&right_child, 1, 1, input);
        
        tree[node][0] = left_child;
        tree[node][1] = right_child;
    }

    dfs(tree, 1, k, 0);

    return 0;
}