/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* tree(int l, int r,const vector<int> &A){
     if(l>r)return NULL;
     if(l==r){
         TreeNode *node = new TreeNode(A[l]);
         return node;
     }
     int m = (l+r)/2;
     TreeNode *node = new TreeNode(A[m]);
     node->left = tree(l, m-1, A);
     node->right = tree(m+1, r, A);
     return node;
 }
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    TreeNode *node = tree(0, n-1, A);
    return node;
}

