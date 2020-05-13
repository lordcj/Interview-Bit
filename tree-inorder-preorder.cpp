/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* build(vector<int> &A, vector<int> &B, int l, int r, int &ind){
     if(ind >= B.size())return NULL;
     if(l > r)return NULL;
     TreeNode *node = new TreeNode(B[ind]);
     int x;
     for(int i=l; i<=r; i++){
         if(B[ind]==A[i]){
             x = i;break;
         }
     }
     ind = ind + 1;
     node->left = build(A, B, l, x-1, ind);
     node->right = build(A, B, x+1, r, ind);
     return node;
 }
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n1 = A.size(), n2 = B.size();
    int ind = 0;
    TreeNode *node = build(B, A, 0, n1-1, ind);
    return node;
}

