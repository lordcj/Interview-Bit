vector<int> Solution::getRow(int A) {
    vector<int> ve,pre;
    ve.push_back(1);
    if(A==0)return ve;
    pre.push_back(1);
    pre.push_back(1);
    ve.push_back(1);
    for(int i=1;i<A;i++){
        ve.clear();
        ve.push_back(1);
        for(int j=1;j<=i;j++)ve.push_back(pre[j-1]+pre[j]);
        ve.push_back(1);
        pre.clear();
        pre=ve;
    }
    return ve;
}

