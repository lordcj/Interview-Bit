vector<int> Solution::nextPermutation(vector<int> &A) {
    stack<int> st;
    int j,x=A.size();
    for(int i=A.size()-1;i>=0;i--){
        if(st.empty()){
            st.push(i);
        }else{
            j = st.top();
            if(A[j]>=A[i]){
                while(!st.empty()){
                    j=st.top();
                    if(A[j]>=A[i])x=j;
                    else break;
                    st.pop();
                }
                swap(A[x],A[i]);
                x=i+1;
                break;
            }else{
                st.push(i);
            }
        }
    }
    if(x!=A.size())sort(A.begin()+x,A.end());
    else sort(A.begin(), A.end());
    return A;
}

