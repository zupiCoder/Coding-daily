#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool evaluateTree(struct TreeNode* root) {
    if(!root) return false;

    if(root-> val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
    if(root-> val == 3) return evaluateTree(root->left) && evaluateTree(root->right);

    return root->val;
}