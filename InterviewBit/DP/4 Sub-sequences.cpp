/*
4 Sub-sequences
Problem Description

You are given an array A of length N. You need to choose 4 non empty disjoint sub sequences of A, let's call them as a1, a2, a3, a4.

Disjoint means if ith index was used in one sub sequence, then it can not be used in other sub sequences.

Let's call the sum of elements in these sub sequences as s1, s2, s3, s4.

Your task is to maximize s1 * s3 such that s1 = s2 and s3 = s4. There can be many ways to choose a1, a2, a3, a4, but final answer will be unique.

Note: if it is not possible to find such sub sequences then return -1.



Problem Constraints
4 <= N <= 14
1 <= A[i] <= 10



Input Format
First argument is an integer array A of size N.



Output Format
Return single integer denoting the answer.



Example Input
A = [7, 7, 3, 3, 10, 9, 4, 3, 3, 4]


Example Output
150


Example Explanation
One possible way of choosing the sub sequences is:
a1 as [A[1], A[2]] = [7, 3] hence s1 = 10.
a2 as [A[4]] = [10] hence s2 = 10.
a3 as [A[0], A[6], A[9]] = [7, 4, 4] hence s3 = 15.
a4 as [A[5], A[7], A[8]] = [9, 3, 3] hence s4 = 15.
So s1 * s3 = 10 * 15 = 150. 
Note that we can not achieve more than 150.


*/


const int N=14,MAX=10;

vector<int>a;
int len;
int pos[N];
unordered_map<int,int>valid;

inline int consider2(int cur)
{
    int ans=-1;
    int ALL=1<<len;
    
    for(int mask=0;mask<ALL;mask++)
    {
        int part1=0,part2=0;
        for(int i=0;i<len;i++)
        {
            if((mask >> i) & 1)
            {
                part1 |=(1 <<pos[i]);
            }
            else
            {
                part2 |=(1 <<pos[i]);
            }
        }
        
        assert((part1 ^ part2)==cur);
        auto it1=valid.find(part1);
        auto it2=valid.find(part2);
        
        if(it1 != valid.end() && it2 !=valid.end())
        {
            ans=max(ans,it1->second*it2->second);
        }
    }
    return ans;
}

inline void consider1(int cur)
{
    int ALL=1<<len;
    for(int mask=0;mask<ALL;mask++)
    {
        int sum1=0,sum2=0;
        for(int i=0;i<len;i++)
        {
            if((mask>>i) & 1)
            {
                sum1 +=a[pos[i]];
            }
            else
            {
                sum2 +=a[pos[i]];
            }
        }
        if(sum1==sum2 && sum1 !=0)
        {
            valid[cur]=sum1;
            return;
        }
    }
}

int Solution::solve(vector<int> &A) {
    valid.clear();
    a=A;
    
    int n=a.size();
    int ALL=1<<n;
    
    for(int mask=0;mask<ALL;mask++)
    {
        len=0;
        for(int i=0;i<n;i++)
        {
            if((mask>>i) & 1)
            {
                pos[len++]=i;
            }
        }
        consider1(mask);
    }
    
    int ans=-1;
    for(int mask=0;mask<ALL;mask++)
    {
        len=0;
        for(int i=0;i<n;i++)
        {
            if((mask >>i )& 1)
            {
                pos[len++]=i;
            }
        }
        ans=max(ans,consider2(mask));
    }
    return ans;
}
