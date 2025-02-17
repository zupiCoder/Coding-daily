#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

bool leaf(struct TreeNode* root) {
    return !root->left && !root->right;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if(!root) return 0;

    int temp = sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

    if(root->left && leaf(root->left)) {
        temp += root->left->val;
    }

    return temp;
}