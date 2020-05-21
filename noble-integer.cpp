int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    for(int i=0;i<A.size();i++){
        if(i!=n-1)if(A[i]==A[i+1])continue;
        if(n-i-1 == A[i])return 1;
    }
    return -1;
}

