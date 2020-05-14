/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> ve;
 int f;
 void traverse(TreeNode* A){
    int prev = INT_MIN, curr, te;
    if(A==NULL)return ;
    TreeNode* root = A, *pre;
    while(root!=NULL){
        if(root->left == NULL){
            curr = root->val;
            if(curr < prev){
                if(ve.size()==0){te=curr;ve.push_back(prev);}
                else ve.push_back(curr);
            }
            prev = curr;
            root = root->right;
        }else{
            pre = root->left;
            while(pre->right!=NULL && pre->right != root)pre = pre->right;
            if(pre->right == NULL){
                pre->right = root;
                root = root->left;
            }else{
                pre->right = NULL;
                curr = root->val;
                if(curr < prev){
                    if(ve.size()==0){te=curr;ve.push_back(prev);}
                    else ve.push_back(curr);
                }
                prev = curr;
                root = root->right;
            }
        }
    }
    if(ve.size()==1)ve.push_back(te);
    //for(int i=0;i<in.size();i++)cout<<in[i]<<" ";cout<<endl;
 }
vector<int> Solution::recoverTree(TreeNode* A) {
    ve.clear();
    f=1;
    traverse(A);
    sort(ve.begin(), ve.end());
    return ve;
}

