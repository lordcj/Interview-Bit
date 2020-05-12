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
 void check(TreeNode *A, TreeNode *B){
     if(A==NULL && B==NULL)return ;
     if(!ans)return ;
     if((A==NULL && B!=NULL) || (B==NULL && A!=NULL) || (A->val != B->val)){
         ans = 0;
         return;
     }
     check(A->left, B->left);
     check(A->right, B->right);
 }
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    ans = 1;
    check(A, B);
    return ans;
}

