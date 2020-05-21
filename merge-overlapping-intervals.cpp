/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(const Interval &a, const Interval &b){
    if(a.start == b.start)return a.end < b.end;
    return a.start < b.start;
} 

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    sort(A.begin(), A.end(), cmp);
    int s=-1,e=-1;
    for(int i=0;i<A.size();i++){
        if(A[i].start <= e){
            e = max(e, A[i].end);
        }else{
            if(e!=-1){
                Interval node = Interval(s,e);
                ans.push_back(node);
            }
            s=A[i].start;
            e=A[i].end;
        }
    }
    if(e!=-1){
        Interval node = Interval(s,e);
        ans.push_back(node);
    }
    return ans;
}

