bool cmp(const string &a, const string &b){
    string ab=a+b, ba=b+a;
    if(ab > ba)return 1;
    else return 0;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> vs;
    for(int i=0;i<A.size();i++){
        string s=to_string(A[i]);
        vs.push_back(s);
    }
    sort(vs.begin(), vs.end(), cmp);
    string ans="";
    for(int i=0;i<vs.size();i++)ans+=vs[i];
    int i;
    for(i=0;i<ans.length();i++)if(ans[i]!='0')break;
    if(i==ans.length())return "0";
    return ans;
}

