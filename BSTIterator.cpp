/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode *node;
stack<TreeNode *> st;
BSTIterator::BSTIterator(TreeNode *root) {
    node = root;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(!node && st.empty())return false;
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int ret;
    while(1){
        if(node){
            st.push(node);
            node = node->left;
            continue;
        }
        node = st.top();
        st.pop();
        ret = node->val;
        node = node->right;
        break;
    }
    return ret;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

