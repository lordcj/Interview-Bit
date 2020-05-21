vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    long long s = (n*(n+1))/2, s1=0;
    long long sq = (n*(n+1)*(2*n+1))/6, sq1=0;
    for(int i=0;i<A.size();i++){
        long long te = A[i];
        s1 += (te);
        sq1 += (te*te);
    }
    long long y = sq1 - sq;
    long long x = s1 - s;
    long long a,b;
    b = (y-(x*x))/(2*x);
    a = (y+(x*x))/(2*x);
    vector<int> ans;
    ans.push_back(int(a));
    ans.push_back(int(b));
    return ans;
}

