/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 pair<TreeNode* , TreeNode*> traverse(TreeNode* A){
     TreeNode *a=NULL, *b=NULL;
     pair<TreeNode* , TreeNode*> pa= make_pair(a,b);
     if(A==NULL)return pa;
     pair<TreeNode* , TreeNode*> l_h = traverse(A->left);
     pair<TreeNode* , TreeNode*> r_h = traverse(A->right);
     if(l_h.first == NULL && r_h.first==NULL)return make_pair(A,A);
     if(l_h.first == NULL){
         return make_pair(A, r_h.second);
     }
     if(r_h.first == NULL){
        A->left = NULL;
        A->right = l_h.first;
        return make_pair(A, l_h.second);
     }
     A->left = NULL;
     A->right = NULL;
     A->right = l_h.first;
     l_h.second->right = r_h.first;
     return make_pair(A, r_h.second);
 }
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    pair<TreeNode* , TreeNode* >pa = traverse(A);
    return pa.first;
}

