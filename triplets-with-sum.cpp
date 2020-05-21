int Solution::solve(vector<string> &A) {
    vector<double> vd;
    for(int i=0;i<A.size();i++)vd.push_back(stod(A[i]));
    double a=vd[0],b=vd[1],c=vd[2];
    //cout<<a<<" "<<b<<" "<<c<<endl;
    for(int i=3;i<vd.size();i++){
        if(a+b+c>1 && a+b+c<2){
            return 1;
        }else if(a+b+c <= 1){
            if(a<=b && a<=c)a=vd[i];
            else if(b<=a && b<=c)b=vd[i];
            else if(c<=a && c<=a)c=vd[i];
        }else if(a+b+c >= 2){
            if(a>=b && a>=c)a=vd[i];
            else if(b>=a && b>=c)b=vd[i];
            else if(c>=a && c>=b)c=vd[i];
        }
    }
    //cout<<a+b+c<<endl;
    if(a+b+c>1 && a+b+c<2)return 1;
    return 0;
}

