/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* traverse(int l, int r, vector<int> &A){
     if(l>r)return NULL;
     if(l==r){
         TreeNode *node = new TreeNode(A[l]);
         return node;
     }
     int ind;
     int val=INT_MIN;
     for(int i=l;i<=r;i++){
         if(A[i]>val){
             val = A[i];
             ind = i;
         }
     }
     TreeNode* node = new TreeNode(A[ind]);
     node->left = traverse(l, ind-1, A);
     node->right = traverse(ind+1, r, A);
     return node;
 }
 
TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    TreeNode *ret = traverse(0, n-1, A);
    return ret;
}

