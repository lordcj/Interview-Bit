bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first == b.first)return a.second < b.second;
    return a.first < b.first;
}

int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> ve;
    for(int i=0;i<A.size();i++)ve.push_back(make_pair(A[i],i));
    sort(ve.begin(), ve.end(), cmp);
    //for(int i=0;i<ve.size();i++)cout<<ve[i].first<<","<<ve[i].second<<" ";cout<<endl;
    int mi=ve[0].second,ans=0;
    for(int i=0;i<A.size();i++){
        ans = max(ans, ve[i].second-mi);
        mi = min(mi,ve[i].second);
    }
    return ans;
}

