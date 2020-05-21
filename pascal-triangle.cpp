vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    vector<int> ve;
    if(A==0)return ans;
    ve.push_back(1);
    ans.push_back(ve);
    for(int i=1;i<A;i++){
        ve.clear();
        ve.push_back(1);
        for(int j=1;j<i;j++){
            int te = ans[i-1][j]+ans[i-1][j-1];
            ve.push_back(te);
        }
        ve.push_back(1);
        ans.push_back(ve);
    }
    //for(int i=0;i<A;i++){for(int j=0;j<A;j++)cout<<ans[i][j]<<" ";cout<<endl;}
    return ans;
}

