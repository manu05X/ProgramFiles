/*
Pair Sum divisible by M

Given an array of integers A and an integer B, find and return the number of pairs in A whose sum is divisible by B.
Since the answer may be large, return the answer modulo (109 + 7).     


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 109
1 <= B <= 106


Input Format
The first argument given is the integer array A.
The second argument given is the integer B.


Output Format
Return the total number of pairs for which the sum is divisible by B modulo (109 + 7).


Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
 B = 2
Input 2:
 A = [5, 17, 100, 11]
 B = 28
    

Example Output
Output 1:
 4

Output 2:
 1
    
Example Explanation
Explanation 1:
 All pairs which are divisible by 2 are (1,3), (1,5), (2,4), (3,5) 
 So total 4 pairs.

*/

//sol->

#define MOD 1000000007
int Solution::solve(vector<int> &A, int B) 
{
    long long int n = A.size();
    long long int m[B];
   
    for(int i=0; i<B; i++)
       m[i]=0;
    
    for(int i = 0; i < n; i++)
    {
        m[A[i]%B]++;
    }
    
    long long int sum=0;
    sum+=(m[0]*(m[0]-1))/2;
     
     for(int i=1; i<=B/2 && i!=B-i; i++)
     {
         sum+=m[i]*m[B-i];
     }
    if(B%2==0)
        sum+=(m[B/2]*(m[B/2]-1))/2;
     
    return (sum)%MOD;
}






/*
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    long long cnt[B];
    memset(cnt,0,sizeof(cnt));
    long long  mod=1e9 +7;
    for(int i=0;i<n;i++)
    {
        cnt[A[i]%B]++;
    }
    long long ans=(cnt[0]*(cnt[0]-1))/2;
    ans%=mod;
    int i=1,j=B-1;
    while(i<=j)
    {
        if(i==j)
        {
            ans+=(cnt[i]*(cnt[j]-1))/2;
            ans%=mod;
        }
        else
        {
            ans+=cnt[i]*cnt[j];
            ans%=mod;
        }
        i++;
        j--;
    }
    return ans;
}
----------------------------------

public class Solution {
    public int solve(int[] a, int k) {
        int n = a.length;
        long mod = (long)(1e9 + 7);
        long cnt[] = new long[k];
        for(int x : a)    cnt[x % k]++;
        long ans = cnt[0] * (cnt[0] - 1) / 2;
        for(int i = 1, j = k-1; i <= j; i++, j--) {
            if(i == j)    ans = (ans + cnt[i] * (cnt[i] - 1) / 2) % mod;
            else    ans = (ans + cnt[i] * cnt[j]) % mod;
        }
        return (int)ans;
    }
}
-----------------------------------
class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        n=len(A)
        mod=1e9+7
        cnt=[0]*B
        for i in A:
            cnt[i%B]+=1
        ans=(cnt[0]*(cnt[0]-1))//2
        i=1
        j=B-1
        while(i<=j):
            if(i==j):
                ans+=(cnt[i]*(cnt[j]-1))//2
                ans%=mod
            else:
                ans+=cnt[i]*cnt[j]
                ans%=mod
            i+=1
            j-=1
        return int(ans)

*/
