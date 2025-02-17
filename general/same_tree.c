#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
    
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    int traversal_p[100];
    int traversal_q[100];

    dfs(p, traversal_p, 0); dfs(q, traversal_q, 0);

    for(int i = 0; i < 100; i++) {
        if(traversal_p[i] != traversal_q[i]) return false;
    }   
    return true;
}      

void dfs(struct TreeNode* p, int stored_traversal[], int node) {

    if(p->left == NULL && p->right == NULL) return;

    if(p->left && p->val != -1) {
        stored_traversal[node] = p->left->val;
        p->val = -1;
        node++;
    }
    
    if(p->right && p->val != -1) {
        stored_traversal[node] = p->right->val;
        p->val = -1;
        node++;
    }

    dfs(p->left, stored_traversal, node);
    dfs(p->right, stored_traversal, node);
}

int main() {

    int n;
    scanf("%d", &n);

    TreeNode t[100];
    TreeNode s[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for(int i = 0; i < n; i++) scanf("%d", &s[i]);

    return 0;
}