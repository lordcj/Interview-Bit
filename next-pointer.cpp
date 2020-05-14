/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode *left, *prev, *curr;
    curr = A;
    while(curr!=NULL){
        while(curr!=NULL){
            if(curr->left!=NULL){
                if(left==NULL)left = curr->left;
                if(prev!=NULL)prev->next = curr->left;
                prev = curr->left;
            }
            if(curr->right!=NULL){
                if(left==NULL)left = curr->right;
                if(prev!=NULL)prev->next = curr->right;
                prev = curr->right;
            }
            curr = curr->next;
        }
        curr = left;
        left = NULL;
        prev = NULL;
    }
}

