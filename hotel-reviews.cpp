struct Trie{
    bool word;
    Trie* t[26];
    Trie() {
        word = false;
        for(int i=0;i<26;i++)t[i]=NULL;
    }
};

void insert(Trie *root, string s){
    for(int i=0;i<s.length();i++){
        if(root->t[s[i]-'a']==NULL){
            root->t[s[i]-'a'] = new Trie();
        }
        root = root->t[s[i]-'a'];
    }
    root->word = true;
}

int search(Trie *root, string s){
    //cout<<s<<" *"<<endl;
    for(int i=0;i<s.length();i++){
        if(root->t[s[i]-'a']!=NULL){
            root = root->t[s[i]-'a'];
        }else return 0;
    }
    if(root->word==true)return 1;
    else return 0;
}

bool cmp(const pair<int,int> &a, const pair<int, int> &b){
    if(a.first==b.first)return a.second < b.second;
    return a.first > b.first;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    set<string> se;
    Trie *root, *root1;
    root = new Trie();
    string te="";
    for(int i=0;i<A.length();i++){
        if(A[i]=='_'){
            root1 = root;
            insert(root1, te);
            te="";
            continue;
        }
        te=te+A[i];
    }
    root1 = root;
    insert(root1,te);
    int x;
    vector<pair<int,int>> ve1;
    for(int i=0;i<B.size();i++){
        te="";
        x=0;
        for(int j=0;j<B[i].length();j++){
            if(B[i][j]=='_'){
                root1 = root;
                if(search(root1,te))x++;
                te="";
                continue;
            }
            te+=B[i][j];
        }
        root1 = root;
        if(search(root1,te))x++;
        ve1.push_back(make_pair(x,i));
    }
    sort(ve1.begin(), ve1.end(), cmp);
    vector<int> ve;
    for(auto p: ve1){
        ve.push_back(p.second);
    }
    return ve;
}

