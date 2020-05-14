/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<vector<int>> ans;
 void traverse(TreeNode* A, int val, int B, vector<int> ve){
     if(A==NULL)return ;
     vector<int> next;
     for(int i=0;i<ve.size();i++)next.push_back(ve[i]);
     val += A->val;
     next.push_back(A->val);
     if(A->left == NULL && A->right == NULL){
         if(val == B)ans.push_back(next);
     }
     traverse(A->left, val, B, next);
     traverse(A->right, val, B, next);
 }
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    ans.clear();
    vector<int> ve;
    traverse(A, 0, B, ve);
    return ans;
}

