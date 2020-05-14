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
 void traverse(vector<TreeNode *> ve, int f){
     vector<TreeNode *> next;
     vector<int> ans1;
     if(f){
         for(int i=0;i<ve.size();i++)ans1.push_back(ve[i]->val);
     }else{
         for(int i=ve.size()-1;i>=0;i--)ans1.push_back(ve[i]->val);
     }
     ans.push_back(ans1);
     for(int i=0;i<ve.size();i++){
         if(ve[i]->left!=NULL)next.push_back(ve[i]->left);
         if(ve[i]->right!=NULL)next.push_back(ve[i]->right);
     }
     
     if(next.size()!=0)traverse(next, (f+1)%2);
 }
 
 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    ans.clear();
    vector<TreeNode*> ve;
    ve.push_back(A);
    traverse(ve,1);
    return ans;
}

