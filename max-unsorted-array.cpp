vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> ve;
    for(int i=0;i<A.size();i++)ve.push_back(A[i]);
    sort(ve.begin(), ve.end());
    int n = A.size();
    int l=0,r=n-1;
    for(int i=0;i<n;i++){
        if(A[i]==ve[i])l++;
        else break;
    }
    for(int i=n-1;i>=0;i--){
        if(A[i]==ve[i])r--;
        else break;
    }
    vector<int> ans;
    if(l==n)ans.push_back(-1);
    else{
        ans.push_back(l);ans.push_back(r);
    }
    return ans;
}

