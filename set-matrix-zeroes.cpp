void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int f=0;
    for(int i=0;i<A.size();i++)if(A[i][0]==0)f=1;
    for(int i=0;i<A[0].size();i++)if(A[0][i]==0){if(f==3)continue;else if(f==1)f=3;else f=2;} 
    if(A[0][0]==0)f=3;
    for(int i=1;i<A.size();i++){
        for(int j=1;j<A[0].size();j++){
            if(A[i][j]==0){
                if(A[i][0]==1)A[i][0]=-1;
                if(A[0][j]==1)A[0][j]=-1;
            }
        }
    }
    for(int i=1;i<A.size();i++){
        if(A[i][0]==0 || A[i][0]==-1){
            for(int j=0;j<A[0].size();j++)A[i][j]=0;
        }
    }
    for(int j=1;j<A[0].size();j++){
        if(A[0][j]==-1 || A[0][j]==0){
            for(int i=0;i<A.size();i++)A[i][j]=0;
        }
    }
    //cout<<f<<endl;
    if(f==1){
        for(int i=0;i<A.size();i++)A[i][0]=0;
    }else if(f==2)for(int i=0;i<A[0].size();i++)A[0][i]=0;
    else if(f==3){
        for(int i=0;i<A.size();i++)A[i][0]=0;
        for(int i=0;i<A[0].size();i++)A[0][i]=0;
    }
    for(int i=0;i<A.size();i++)if(A[i][0]==-1)A[i][0]=1;
    for(int i=0;i<A[0].size();i++)if(A[0][i]==-1)A[0][i]=1;
}

