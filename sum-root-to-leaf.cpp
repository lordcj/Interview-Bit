/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int ans, mod = 1003;
 void traverse(TreeNode* A, int num){
     if(A==NULL)return ;
     num = num*10+(A->val);
     if(A->left==NULL && A->right==NULL){
         ans = (ans + num%mod)%mod;
         if(ans<0)ans = ans+mod;
     }
     traverse(A->left, num);
     traverse(A->right, num);
 }
 
int Solution::sumNumbers(TreeNode* A) {
    ans = 0;
    traverse(A, 0);
    return ans;
}

