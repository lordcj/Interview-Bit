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
 void ksmall(TreeNode *A, int &ind){
     if(A==NULL)return ;
     ksmall(A->left, ind);
     ind -= 1;
     if(ind == 0)ans=A->val;
     ksmall(A->right, ind);
 }
 
int Solution::kthsmallest(TreeNode* A, int B) {
    ksmall(A, B);
    return ans;
}

