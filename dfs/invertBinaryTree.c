struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

void invertHelper(struct TreeNode* root);

struct TreeNode* invertTree(struct TreeNode* root) {

    invertHelper(root);

    return root;
}

void invertHelper(struct TreeNode* root) {
    if(!root) return;

    invertHelper(root->left);
    invertHelper(root->right);
    
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}