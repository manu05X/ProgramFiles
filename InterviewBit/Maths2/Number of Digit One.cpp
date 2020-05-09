/*
Number of Digit One
Problem Description
Given an integer A, find and return the total number of digit 1 appearing in all non-negative integers less than or equal to A.


Problem Constraints
0 <= A <= 109


Input Format
The only argument given is the integer A.


Output Format
Return the total number of digit 1 appearing in all non-negative integers less than or equal to A.


Example Input
Input 1:
 A = 10
Input 2:
 A = 11


Example Output
Output 1:
 2
Output 2:
 4


Example Explanation
Explanation 1:
Digit 1 appears in 1 and 10 only and appears one time in each. So the answer is 2.
Explanation 2:
Digit 1 appears in 1(1 time) , 10(1 time) and 11(2 times) only. So the answer is 4.


*/

//sol->


int Solution::solve(int A) {
        if (A <= 0)
            return 0;   
        
    int q = A, x = 1, ans = 0;  
        do {
      int digit = q % 10;   
      q /= 10;       
      ans += q * x;   
      if (digit == 1) 
        ans += A % x + 1;     
      if (digit >  1)
        ans += x;     
      x *= 10;   
      }
      while (q > 0); 
      return ans; 
}






/*
int Solution::solve(int A) {
    int ans = 0;
    for (int i = 1; i <= A; i *= 10) {
        int divider = i * 10;
        ans += (A / divider) * i + min(max(A % divider - i + 1, 0), i);
    }
    return ans;
}
----------------------------------

public class Solution {
    public int solve(int A) {
        int ans = 0;
        for (int i = 1; i <= A; i *= 10) {
            int divider = i * 10;
            ans += (A / divider) * i + Math.min(Math.max(A % divider - i + 1, 0), i);
        }
        return ans;
    }
}
-----------------------------------
class Solution:
    # @param A : integer
    # @return an integer
    def solve(self, A):
        ans = 0
        i = 1
        while(i <=A):
            divider = i * 10;
            ans += (A // divider) * i + min(max(A % divider - i + 1, 0), i)
            i = i * 10
        return int(ans)
---------------------------------
int countDigitOne(int n)
{
    int countr = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
    return countr;
}
int Solution::solve(int A) {
    return countDigitOne(A);
}

*/
