/*
Counting Triangles
You are given an array of N non-negative integers, A0, A1 ,..., AN-1. Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values. Notes:
You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn't matter. Any triangle formed should have a positive area.
Return answer modulo 109 + 7.


For example,
A = [1, 1, 1, 2, 2]

Return: 4
*/

# define mod 1000000007
int Solution::nTriang(vector<int> &A) 
{
    int count=0;
    if(!A.size())
		return count;
    
    sort(A.begin(),A.end());
    
    for(int i=A.size()-1;i>=0;i--)
    {
        int l=0,r=i-1;
        while(l<r)
        {
            if(A[l]+A[r]>A[i])
            {
                count=(count+(r-l)%mod)%mod;
                r--;
            }
            else 
                l++;
        }
    }
    return count;
}