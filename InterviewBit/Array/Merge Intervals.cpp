/*
Merge Intervals
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). 
You may assume that the intervals were initially sorted according to their start times.
 Example 1: Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9]. 
 Example 2: Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16]. 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
Make sure the returned intervals are also sorted.
*/

//sol->

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
       int i;
   vector<Interval> A;
   for(i=0;i<intervals.size();i++)
   {
       if(newInterval.start>intervals[i].start && newInterval.start>intervals[i].end)
       {
           A.push_back(intervals[i]);
       }
       else
           break;
   }
   Interval s;
   if(i!=intervals.size() && intervals[i].start<newInterval.start )
        s.start=intervals[i].start;
    else if(i!=intervals.size())
        s.start=newInterval.start;
   if(i==intervals.size())
   {    s.start=newInterval.start;
        s.end=newInterval.end;
   }
   int f=0;
   while(i<intervals.size())
   {
       if(newInterval.end>=intervals[i].start && newInterval.end<intervals[i].end)
       {
           s.end=intervals[i].end;
           i++;
           f=1;
           break;
       }
       else if(newInterval.end<intervals[i].start )
       {
           s.end=newInterval.end;
           f=1;
           break;
       }
       i++;
   }
   if(f==0)
    s.end=newInterval.end;
   A.push_back(s);
   while(i<intervals.size())
   {
       A.push_back(intervals[i]);
       i++;
   }
   return A;
}
/*
class Solution {
    public:

        bool doesIntersect(Interval a, Interval b) {
            if (min(a.end, b.end) < max(a.start, b.start)) return false;
            return true;
        }

        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            int sz = intervals.size();
            vector<Interval> result; 

            // check corner cases
            // Case : Empty intervals array
            if (sz == 0) {
                result.push_back(newInterval);
                return result;
            }
            // Case : newInterval comes at the beginning or at the end without overlap 
            if (newInterval.start > intervals[sz - 1].end || newInterval.end < intervals[0].start) {
                if (newInterval.end < intervals[0].start) {
                    result.push_back(newInterval);
                }
                for (int i = 0; i < sz; i++) {
                    result.push_back(intervals[i]);
                }
                if (newInterval.start > intervals[sz - 1].end) {
                    result.push_back(newInterval);
                }
                return result;
            }
            for (int i = 0; i < sz; i++) {
                bool intersect = doesIntersect(intervals[i], newInterval);
                if (!intersect) {
                    result.push_back(intervals[i]);
                    // check if newInterval lies between intervals[i] and intervals[i+1]
                    if (i < sz - 1 && newInterval.start > intervals[i].end && newInterval.end < intervals[i+1].start) {
                        result.push_back(newInterval);
                    }
                    continue;
                }
                // Now we know the interval overlaps. Lets find out how many intervals overlap. 
                int st = i; 
                while (i < sz && intersect) {
                    i++;
                    if (i == sz) intersect = false; 
                    else {
                        intersect = doesIntersect(intervals[i], newInterval);
                    }
                }
                i--;
                // Now all intervals from st to i overlap. 
                Interval toInsert(min(newInterval.start, intervals[st].start), max(newInterval.end, intervals[i].end));
                result.push_back(toInsert);
            }
            return result;
        }
};
*/