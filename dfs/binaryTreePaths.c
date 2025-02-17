struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

void dfs(struct TreeNode* root, int* returnSize, char** t, char* temp, int tempLen);
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {

    char** t = calloc(100, sizeof(char*));
    char* temp = calloc(100, sizeof(char));
    *returnSize = 0;

    dfs(root, returnSize, t, temp, 0);
    free(temp);
    return t;
}
void dfs(struct TreeNode* root, int* returnSize, char** t, char* temp, int tempLen) {
    if (!root) return;

    int currentLen = tempLen;

    if (currentLen > 0) {
        strcat(temp, "->");
        currentLen += 2;
    }

    char numStr[5];
    sprintf(numStr, "%d", root->val);
    strcat(temp, numStr);
    currentLen += strlen(numStr);

    if (!root->left && !root->right) {
        t[*returnSize] = strdup(temp);
        (*returnSize)++;
    }

    dfs(root->left, returnSize, t, temp, currentLen);
    dfs(root->right, returnSize, t, temp, currentLen);
    temp[tempLen] = '\0';
}