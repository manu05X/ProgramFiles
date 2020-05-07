/*
Merge Overlapping Intervals
Given a collection of intervals, merge all overlapping intervals. For example: Given [1,3],[2,6],[8,10],[15,18], return [1,6],[8,10],[15,18]. Make sure the returned intervals are sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(Interval i1, Interval i2)
 {
     return (i1.start < i2.start);
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    /* Do not write main() function.
     Do not read input, instead use the arguments to the function.
     Do not print the output, instead return values as specified
     Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details */
    
    vector<Interval> ans; //new ans vector initilization
    sort(A.begin(),A.end(),comp);  //sorting the interval in increasing order 
    
    Interval s;             //new interval s is define
                            // first element of loop i.e A[0]
    s.start = A[0].start;   //A's first element (1 in [1,3])
    s.end = A[0].end;       //A's second element(3 in [1,3]) 
    
    int i=1;                //loop start from 1 i.e from 2nd interval [2,6] 
    while(i<A.size())
    {
        if(A[i].start > s.end)  // if 2 > 3 i.e is wrong therefor else is executed
        {
            ans.push_back(s);
            s.start=A[i].start;
            s.end=A[i].end;
        }
        else if(A[i].end > s.end)  // if 6 > 3 this is executed as it is true
        {
             s.end=max(A[i].end,s.end); // interval is merged
        }
        i++;                          //increasing i for next interval
    }
    ans.push_back(s);
    return ans;
}
