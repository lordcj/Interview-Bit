bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first==b.first)return a.second < b.second;
    return a.first < b.first;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>> ve;
    
    for(int i=0;i<arrive.size();i++)ve.push_back(make_pair(arrive[i], depart[i]));
    sort(ve.begin(), ve.end(), cmp);
    auto cmp1 = [](pair<int,int> a, pair<int,int> b) {
        if(a.second == b.second)return a.first < b.first;
        return a.second < b.second;
    };
    set<pair<int, int>, decltype(cmp1)> se(cmp1);
    for(int i=0;i<ve.size();i++){
        int x = ve[i].first, y = ve[i].second;
        if(x==y)continue;
        //cout<<x<<" "<<y<<endl;
        if(se.empty())se.insert(ve[i]);
        else{
            while(!se.empty()){
                pair<int,int> pa = *se.begin();
                if(pa.second <= x)se.erase(pa);
                else break;
            }
            se.insert(ve[i]);
        }
        //for(auto p: se)cout<<p.first<<","<<p.second<<" ";cout<<endl;
        if(se.size()>K)return 0;
    }
    return 1;
}

