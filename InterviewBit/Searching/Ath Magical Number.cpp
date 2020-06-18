/*
Ath Magical Number
Problem Description

Given three positive integers A, B and C.

Any positive integer is magical if it is divisible by either B or C.

Return the Ath magical number. Since the answer may be very large, return it modulo 109 + 7.



Problem Constraints
1 <= A <= 109

2 <= B, C <= 40000



Input Format
The first argument given is an integer A.

The second argument given is an integer B.

The third argument given is an integer C.



Output Format
Return the Ath magical number. Since the answer may be very large, return it modulo 109 + 7.



Example Input
Input 1:

 A = 1
 B = 2
 C = 3
Input 2:

 A = 4
 B = 2
 C = 3


Example Output
Output 1:

 2
Output 2:

 6


Example Explanation
Explanation 1:

 1st magical number is 2.
Explanation 2:

 First four magical numbers are 2, 3, 4, 6 so the 4th magical number is 6.
 
*/

int solveit(int N,int A,int B)
{
  long long ab=(1LL*A*B)/__gcd(A,B);
  long long l=1LL,r=(long long)(1e18),m,ans;
  long long mod=1000000007;
  
  while(l<=r)
  {
      m=(l+r)>>1;
      long long temp=m/A+m/B-m/ab;
      if(temp>=N)
      {
          ans=m;
          r=m-1;
      }
      else
        l=m+1;
  }
  return (int)(ans%mod);
}    

int Solution::solve(int A, int B, int C) {
  return solveit(A,B,C);
}



/*

int solveit(int N, int A, int B) {
    long long ab=(1LL*A*B)/__gcd(A,B);
    long long l=1LL,r=(long long)(1e18),m,ans;
    long long mod=1000000007;
    while(l<=r){
        m=(l+r)>>1;
        long long temp=m/A+m/B-m/ab;
        if(temp>=N){
            ans=m;
            r=m-1;
        }
        else
            l=m+1;
        }
    return (int)(ans%mod);
}

int Solution::solve(int A, int B, int C) {
    return solveit(A,B,C);
}





def computeGCD(x, y): 
  
   while(y): 
       x, y = y, x % y 
  
   return x 
mod=1000000007
class Solution:
    # @param A : integer
    # @param B : integer
    # @param C : integer
    # @return an integer
    def solve(self, A, B, C):
        global mod
        low=2
        high=1000000000000000000
        ans=0
        a=B
        b=C
        lc=(a*b)//computeGCD(a,b)
        while(low<=high):
            mid=low+(high-low)//2
            ct=mid//a + mid//b - mid//lc
            if(ct>=A):
                ans=mid
                high=mid-1
            else:
                low=mid+1
        ans%=mod
        return ans

*/
