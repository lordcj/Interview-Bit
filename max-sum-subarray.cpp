int Solution::maxSubArray(const vector<int> &A) {
    int ans=INT_MIN,te=0;
    for(int i=0;i<A.size();i++)ans = max(ans, A[i]);
    for(int i=0;i<A.size();i++){
        te += A[i];
        ans = max(ans, te);
        if(te<=0)te=0;
    }
    return ans;
}

