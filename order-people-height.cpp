int seg[6*100000]={0};

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<int> ve1;
    ve1.assign(A.size(),0);
    vector<pair<int, int>> ve;
    for(int i=0;i<A.size();i++)ve.push_back(make_pair(A[i],B[i]));
    sort(ve.begin(), ve.end(), cmp);
    for(int i=0;i<ve.size();i++){
        int a = ve[i].first, b = ve[i].second+1;
        int c=0,j;
        for(j=0;j<ve1.size();j++){if(ve1[j]==0)c++;if(c==b){ve1[j]=a;break;}}
    }
    return ve1;
}

