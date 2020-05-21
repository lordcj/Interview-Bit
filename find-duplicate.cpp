int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ve;
    for(int i=0;i<A.size();i++)ve.push_back(A[i]);
    sort(ve.begin(), ve.end());
    for(int i=0;i<ve.size()-1;i++){
        if(ve[i]==ve[i+1])return ve[i];
    }
    return -1;
}

