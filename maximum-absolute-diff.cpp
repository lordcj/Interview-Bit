int Solution::maxArr(vector<int> &A) {
    int m1=INT_MAX,m1_1=INT_MIN,m2=INT_MAX,m2_1=INT_MIN;
    int ans = INT_MIN;
    for(int i=0;i<A.size();i++){
        m1 = min(m1, A[i]-i);
        m1_1 = max(m1_1, A[i]-i);
        m2 = min(m2, A[i]-i);
        m2_1 = max(m2_1, A[i]-i);
        ans = max(ans, max(abs(m1-m1_1), abs(m2-m2_1)));
    }
    return ans;
}

