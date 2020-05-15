struct TrieNode{
    int used;
    int i;
    int index;
    struct TrieNode* ve[26];
    
};

TrieNode* create(int ind, int in){
    TrieNode* tr = new TrieNode();
    tr->used = 0;
    tr->i = in;
    tr->index = ind;
    memset(tr->ve, NULL, sizeof(tr->ve));
    return tr;
}

vector<int> ind;

void insert(string s, TrieNode *node, int inde){
    int f=0;
    //cout<<s<<" **"<<endl;
    for(int i=0;i<s.length();i++){
        if(node->ve[s[i]-'a']==NULL){
            node->ve[s[i]-'a'] = create(inde, i);
            if(!f){f=1;ind[inde] = i;}
            node = node->ve[s[i]-'a'];
        }else{
            node = node->ve[s[i]-'a'];
            //if(s=="duck")cout<<node->index<<" "<<node->i<<endl;
            if(node->used == 0){
                node->used = 1;
                ind[node->index] = node->i+1;
            }
        }
    }
}

vector<string> Solution::prefix(vector<string> &A) {
    ind.clear();
    ind.assign(A.size(), 0);
    string s;
    vector<string> vs;
    TrieNode *root, *node;
    root = create(-1,-1);
    for(int i=0;i<A.size();i++){
        node = root;
        insert(A[i], node, i);
        //for(int j=0;j<A.size();j++)cout<<ind[j]<<" ";cout<<endl;
    }
    for(int i=0;i<A.size();i++){
        //cout<<A[i]<<" ";
        string ret = "";
        for(int j=0;j<=ind[i];j++)ret+=A[i][j];
        vs.push_back(ret);
        //cout<<ret<<endl;
    }
    return vs;
}

