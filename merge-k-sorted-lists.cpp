/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<pair<int,ListNode*>> se;
    ListNode *li = NULL, *ret=NULL;
    for(int i=0;i<A.size();i++)se.insert(make_pair((A[i]->val), A[i]));
    while(!se.empty()){
        pair<int, ListNode*> p = *se.begin();
        //cout<<p.first<<endl;
        se.erase(p);
        if(li==NULL){
            li = new ListNode(p.first);
            ret = li;
        }else{
            li = li->next;
            li = new ListNode(p.first);
        }
        //cout<<li->val<<endl;
        ListNode *te = p.second;
        if(te->next!=NULL){
            te = te->next;
            se.insert(make_pair((te->val), te));
        }
    }
    while(ret!=NULL){
        cout<<ret->val<<" ";
        ret = ret->next;
    }
    return ret;
}

