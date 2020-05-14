/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int ans;
 void traverse(TreeNode* A, int val, int B){
     if(A==NULL || ans==1)return ;
     val = val + A->val;
     if(A->left == NULL && A->right == NULL){
         if(val == B){ans=1;return ;}
     }
     traverse(A->left, val, B);
     traverse(A->right, val, B);
 }
 
int Solution::hasPathSum(TreeNode* A, int B) {
    ans = 0;
    traverse(A, 0, B);
    return ans;
}

