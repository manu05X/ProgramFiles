/*
Aggressive cows
Problem Description

Farmer John has built a new long barn, with N stalls. Given an array of integers A of size N where each element of the array represents the location of the stall, and an integer B which represent the number of cows.

His cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, John wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?



Problem Constraints
2 <= N <= 100000
0 <= A[i] <= 109
2 <= B <= N



Input Format
The first argument given is the integer array A.
The second argument given is the integer B.



Output Format
Return the largest minimum distance possible among the cows.



Example Input
Input 1:

A = [1, 2, 3, 4, 5]
B = 3
Input 2:

A = [1, 2]
B = 2


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 
John can assign the stalls at location 1,3 and 5 to the 3 cows respectively.
So the minimum distance will be 2.
Explanation 2:

 
The minimum distance will be 1.

 
*/

typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int Solution::solve(vector<int> &a, int B) 
{

    ll n,c;
    n = a.size();
    c = B;
    sort(a.begin(),a.end());
    ll i=1,j=1000000001,ans=0,l=0;
    while(i<=j)
    {
        ll mid=((j+i)/2);
        int fi=a[0],temp=1;
        for(int k=1;k<n;k++)
        {
            if(a[k]-fi>=mid)
                temp++,fi=a[k];
        }
        if(temp<c)
            j=mid-1;
        else
        {
            ans=mid;
            i=mid+1;
        }
    }
    return ans;
}


/*

bool check(int x,vector<int> A,int c)
{
    int j=0,n=A.size();
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(A[i]-A[j]>=x)
        {
            j=i;
            cnt++;
        }
    }
    return (cnt>=c);
}


int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    sort(A.begin(),A.end());
    assert(B<=n &&B>=2);
    int l=1,r=1e9;
    int ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid,A,B))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}

*/
