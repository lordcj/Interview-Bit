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

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ve,ans;
    if(newInterval.start > newInterval.end)swap(newInterval.end, newInterval.start);
    for(int i=0;i<intervals.size();i++)ve.push_back(intervals[i]);ve.push_back(newInterval);
    sort(ve.begin(), ve.end(), cmp);
    int s=-1,e=-1;
    for(int i=0;i<ve.size();i++){
        if(ve[i].start <= e){
            e = max(e, ve[i].end);
        }else{
            if(e!=-1){
                Interval node = Interval(s,e);
                ans.push_back(node);
            }
            s=ve[i].start;
            e=ve[i].end;
        }
    }
    if(e!=-1){
        Interval node = Interval(s,e);
        ans.push_back(node);
    }
    return ans;
}

