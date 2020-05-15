/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int ans, f;
 int traverse(TreeNode* A, int B, int C){
     if(A==NULL)return 0;
     int t=0,l,r;
     if(A->val == B || A->val == C){if(B==C)t++;t++;}
     l = traverse(A->left, B, C);
     r = traverse(A->right, B, C);
     if(t+l+r>=2 && f==0){
         f=1;
         ans = A->val;
     }
    if(l>=1 || r>=1 || t>=1)return 1;
    return 0;
 }
 
int Solution::lca(TreeNode* A, int B, int C) {
    f=0;ans=-1;
    traverse(A, B, C);
    return ans;
}

