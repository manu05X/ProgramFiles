/*
Smallest Good Base
Given an integer A, we call k >= 2 a good base of A, if all digits of A base k are 1. Now given a string representing A, you should return the smallest good base of A in string format.


Input Format

The only argument given is the string representing A.
Output Format

Return the smallest good base of A in string format.
Constraints

3 <= A <= 10^18
For Example

Input 1:
    A = "13"
Output 1:
    "3"     (13 in base 3 is 111)

Input 2:
    A = "4681"
Output 2:
    "8"     (4681 in base 8 is 11111).

 
*/

size_t try_k(size_t n, int k)
{
    double ord=1.0/(k-1);
    double root=pow(n,ord);
    size_t a=floor(root);
    
    if(a<2)
        return 0;
        
    size_t sum=1;
    for(int i=0;i<k-1;i++)
            sum=sum*a+1;
        
    if(sum!=n)
        return 0;
    return a;
}

string Solution::solve(string A) {
    
    size_t n=stoull(A);
    for(int k=63;k>=3;k--)
    {
        size_t result=try_k(n,k);
        if(result>0)
            return to_string(result);
    }
    return to_string(n-1);
}

/*

public class Solution {
    
    long play(long n, int d) {
        double t = n;
        long r = (long)(Math.pow(t, 1.0 / d) + 1);
        long l = 1;
        while(l <= r) {
            long m = l + (r - l) / 2;
            long sum = 1, cur = 1;
            for(int i = 1; i <= d; i++) {
                cur *= m;   sum += cur;
            }
            if(sum == n)    return m;
            if(sum > n)     r = m - 1;
            else    l = m + 1;
        }
        return 0;
    }
    
    public String solve(String A) {
        long n = Long.parseLong(A);
        long x = 1;
        for(int i = 62; i >= 1; i--) {
            if((x << i) < n) {
                long cur = play(n, i);
                if(cur != 0) {
                    return (cur +"");
                }
            }
        }
        return (n-1 +"");
    }
}

*/
