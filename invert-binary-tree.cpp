/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* invert(TreeNode *A){
     TreeNode *ret=NULL;
     if(A==NULL)return A;
     else{
         ret = new TreeNode(A->val);
         ret->left = invert(A->right);
         ret->right = invert(A->left);
         return ret;
     }
 }
 
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL)return A;
    TreeNode *ret = invert(A);
    return ret;
}

