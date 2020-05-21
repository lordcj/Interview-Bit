vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ve(B,0);
    string s=A;
    if(s[B-2]=='I')s=s+'I';
    else s=s+'D';
    //cout<<s<<endl;
    int c =1;
    for(int i=0;i<s.length();i++)if(s[i]=='I'){ve[i]=c;c++;}
    c=B;
    for(int i=0;i<s.length();i++)if(s[i]=='D'){ve[i]=c;c--;}
    return ve;
}

