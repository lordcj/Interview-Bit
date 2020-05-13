/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  
 TreeNode* build(vector<int> &A, int n1, vector<int> &B, int n2, int l, int r, int &ind){
     //printf("%d %d %d\n",ind,l,r);
     if(ind < 0)return NULL;
     if(l>r)return NULL;
     TreeNode *node = new TreeNode(B[ind]);
     //printf("%d %d\n",B[ind], ind);
     int x, i;
     for(i=l;i<=r;i++){
         if(A[i]==B[ind]){
             x = i;break;
         }
     }
     ind = ind -1 ;
     node->right = build(A, n1, B, n2, x+1, r, ind);
     node->left = build(A, n1, B, n2, l, x-1, ind);
     return node;
 }
 

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n1 = A.size(), n2 = B.size();
    int ind = n2-1;
    //printf("%d **\n",ind);
    TreeNode *node = build(A, n1, B, n2, 0, n1-1, ind);
    return node;
}

