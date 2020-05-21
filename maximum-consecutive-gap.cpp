int Solution::maximumGap(const vector<int> &A) {
    vector<int> ve;
    for(int i=0;i<A.size();i++)ve.push_back(A[i]);
    sort(ve.begin(), ve.end()); //radix sort could have been used
    int ans=INT_MIN;
    if(ve.size()<2)return 0;
    for(int i=0;i<ve.size()-1;i++)ans = max(ans, ve[i+1]-ve[i]);
    return ans;
}

