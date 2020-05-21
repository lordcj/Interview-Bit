int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int a=0,b=0,c1=0,c2=0,n=A.size();
    for(int i=0;i<A.size();i++){
        if(A[i]==a){
            c1++;
        }else if(A[i]==b){
            c2++;
        }else if(c1==0){
            a=A[i];c1=1;
        }else if(c2==0){
            b=A[i];c2=1;
        }else{
            c1--;c2--;
        }
    }
    //cout<<a<<" "<<b<<endl;
    int x=0;
    for(int i=0;i<A.size();i++)if(a==A[i])x++;
    if(x>(n/3))return a;
    x=0;
    for(int i=0;i<A.size();i++)if(b==A[i])x++;
    if(x>(n/3))return b;
    return -1;
}

