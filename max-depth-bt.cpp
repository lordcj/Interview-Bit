/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int d;
 void dfs(TreeNode* A, int l){
     if(A==NULL)return ;
     d = max(d, l);
     dfs(A->left, l+1);
     dfs(A->right, l+1);
 }
 
int Solution::maxDepth(TreeNode* A) {
    d = 0;
    dfs(A, 1);
    return d;
}

