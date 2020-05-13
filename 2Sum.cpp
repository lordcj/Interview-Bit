bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second)return a.first < b.first;
    return a.second < b.second;
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int>ve,ans;
    vector<pair<int, int>> vll;
    map<int, int> ma, ma1;
    for(int i=0;i<A.size();i++){
        if(ma.find(A[i])==ma.end()){
            ma[A[i]]=i;ve.push_back(A[i]);
        }else{
            if(A[i]*2 == B)vll.push_back(make_pair(ma[A[i]], i));
        }
    }
    sort(ve.begin(), ve.end());
    int a = 0, b = ve.size()-1;
    while(a < b){
        if(ve[a]+ve[b] > B){
            b--;
        }else if(ve[a]+ve[b] < B){
            a++;
        }else{
            if(ma[ve[a]] < ma[ve[b]])vll.push_back(make_pair(ma[ve[a]], ma[ve[b]]));
            else vll.push_back(make_pair(ma[ve[b]], ma[ve[a]]));
            a++;
        }
    }
    sort(vll.begin(), vll.end(), cmp);
    if(vll.size()!=0){ans.push_back(vll[0].first+1);ans.push_back(vll[0].second+1);}
    return ans;
}

