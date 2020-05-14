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
 void traverse(TreeNode* A, int l){
     if(A==NULL)return ;
     if(A->left==NULL && A->right == NULL)d = min(d, l);
     traverse(A->left, l+1);
     traverse(A->right, l+1);
 }
int Solution::minDepth(TreeNode* A) {
    d = INT_MAX;
    traverse(A, 1);
    return d;
}

