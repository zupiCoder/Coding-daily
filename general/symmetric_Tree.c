#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

bool is_symmetric() {
    
}

int main() {

    int n;
    scanf("%d", &n);

    TreeNode t[1000];

    for(int i = 0; i < n; i++) scanf("%d", &t[i]);



    return 0;
}