int recur(int A, int dp[101][101], int mod){
    if(A<=1)return 1;
    int h = log2(A);
    int m = (1<<h);
    int n = A - (m-1);
    int l;
    if(n >= m/2)l=m-1;
    else l = n+(m/2-1);
    int ret = (((recur(l, dp, mod)*1LL*recur(A-l-1, dp, mod))%mod)*1LL*dp[A-1][l])%mod;
    return ret%mod;
}

int Solution::solve(int A) {
    int mod = 1000000007;
    int dp[101][101]={0};
    for(int i=0;i<101;i++){dp[i][i]=1;dp[i][0]=1;}
    for(int i=1;i<101;i++){
        for(int j=1;j<i;j++){
            dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    int ans = recur(A, dp, mod)%mod;
    return ans;
}

