bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first==b.first)return a.second < a.second;
    return a.first < b.first;
}

int Solution::maxSpecialProduct(vector<int> &A) {
    int mod = 1000000007;
    stack<long long> st;
    st.push(0);
    long long l[A.size()]={0}, r[A.size()]={0};
    st.push(0);
    for(long long i=1;i<A.size();i++){
        while(!st.empty()){
            long long j = st.top();
            if(A[j] > A[i]){
                l[i]=j;
                break;
            }else st.pop();
        }
        st.push(i);
    }
    while(!st.empty())st.pop();
    st.push(A.size()-1);
    for(long long i=A.size()-2;i>=0;i--){
        while(!st.empty()){
            long long j=st.top();
            if(A[j]>A[i]){r[i]=j;break;}
            else st.pop();
        }
        st.push(i);
    }
    long long ans=0;
    for(long long i=0;i<A.size();i++)ans=max(ans, (l[i]*1LL*r[i])%mod);
    return ans%mod;
}

