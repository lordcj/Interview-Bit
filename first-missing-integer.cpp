int Solution::firstMissingPositive(vector<int> &A) {
    int pos=A.size();
    for(int i=0;i<A.size();i++)if(A[i]<=0){pos=i;break;}
    for(int i=0;i<A.size();i++){
        if(A[i]>0 && i>pos){
            swap(A[i],A[pos]);
            pos++;
            while(pos<A.size()){
                if(A[pos]<=0)break;
                pos++;
            }
        }
    }
    //for(int i=0;i<A.size();i++)cout<<A[i]<<" ";cout<<endl;
    int lim=A.size();
    for(int i=0;i<A.size();i++)if(A[i]<=0){lim=i-1;break;}
    //cout<<lim<<endl;
    for(int i=0;i<=lim;i++){
        if(abs(A[i])-1 <= lim){
            if(A[abs(A[i])-1] > 0)A[abs(A[i])-1] *= -1;
        }
    }
    //cout<<endl;
    //for(int i=0;i<A.size();i++)cout<<A[i]<<" ";cout<<endl;
    //for(int i=lim+1;i<A.size();i++)cout<<A[i]<<" ";cout<<endl;
    int ans=1;
    for(int i=0;i<=lim;i++)if(A[i]>0){ans=i+1;break;}
    return ans;
}

