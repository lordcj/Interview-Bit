vector<int> Solution::plusOne(vector<int> &A) {
    int c=0,te;
    vector<int> ans;
    A[A.size()-1]++;
    int ch=A.size();
    for(int i=0;i<A.size();i++)if(A[i]!=0){ch=i;break;}
    for(int i=A.size()-1;i>=ch;i--){
        te = (A[i]+c)%10;
        c = (A[i]+c)/10;
        ans.push_back(te);
    }
    if(c!=0)ans.push_back(c);
    reverse(ans.begin(), ans.end());
    return ans;
}

