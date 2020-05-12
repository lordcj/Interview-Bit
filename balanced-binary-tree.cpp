/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool ans;
 int check(TreeNode *A, int h){
    int l=h,r=h;
    if(A->left!=NULL)l = check(A->left, h+1);
    if(A->right!=NULL)r = check(A->right, h+1);
    if(abs(l-r)>1)ans=false;
    return max(l,r);
 }
 
int Solution::isBalanced(TreeNode* A) {
    ans = true;
    check(A, 0);
    return ans;
}

