/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> ans;
 
 void traverse(TreeNode *A){
     if(A==NULL)return;
     traverse(A->left);
     traverse(A->right);
     ans.push_back(A->val);
 }

vector<int> Solution::postorderTraversal(TreeNode* A) {
    ans.clear();
    traverse(A);
    return ans;
}

