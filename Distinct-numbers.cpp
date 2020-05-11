vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ve;
    int n = A.size();
    if(B > n)return ve;
    map<int, int> ma;
    int ans=0;
    for(int i=0;i<B-1;i++){
        if(ma.find(A[i])==ma.end()){
            ans++;
            ma[A[i]]=1;
        }else{
            ma[A[i]]++;
        }
    }
    for(int i=B-1;i<n;i++){
        if(ma.find(A[i])==ma.end()){
            ans++;
            ma[A[i]]=1;
        }else{
            if(ma[A[i]]==0)ans++;
            ma[A[i]]++;
        }
        ve.push_back(ans);
        ma[A[i-B+1]]-=1;
        if(ma[A[i-B+1]]==0)ans--;
    }
    return ve;
}

