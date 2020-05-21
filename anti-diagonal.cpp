vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> ans;
    vector<int> ve;
    int a=0,b=0,n=A.size();
    for(int i=0;i<n;i++){
        ve.clear();
        a=0;b=i;
        while(a>=0&&a<n&&b>=0&&b<n){
            ve.push_back(A[a][b]);
            a++;b--;
        }
        ans.push_back(ve);
    }
    for(int i=1;i<n;i++){
        ve.clear();
        a=i;b=n-1;
        while(a>=0&&a<n&&b>=0&&b<n){
            ve.push_back(A[a][b]);
            a++;b--;
        }
        ans.push_back(ve);
    }
    return ans;
}

