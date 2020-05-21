vector<int> Solution::maxset(vector<int> &A) {
    long long sum=INT_MIN,a=-1,te=0;
    vector<int> ans, ve;
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            te=0;
            ve.clear();
            a=-1;
            continue;
        }else{
            te=te+A[i];
            ve.push_back(A[i]);
            if(a==-1)a=i;
            if(te > sum){
                sum = te;
                ans.clear();
                ans = ve;                
            }else if(te==sum){
                if(ve.size() > ans.size()){
                    sum = te;
                    ans.clear();
                    ans = ve;
                }
            }
        }
    }
    
    return ans;
}

