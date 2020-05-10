/*
Sorted Permutation Rank
Problem Description
Given a string A. Find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated. Note: The answer might not fit in an integer, so return your answer % 1000003  


Problem Constraints
1 <= |A| <= 1000


Input Format
First argument is a string A.


Output Format
Return an integer denoting the rank of the given string.


Example Input
Input 1:
A = "acb"
 Input 2: 
A = "a"
 


Example Output
Output 1:
2
 Output 2: 
1
 


Example Explanation
Explanation 1:
Given A = "acd".
The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
So, the rank of A is 2.
 Explanation 2: 
Given A = "a".
Rank is clearly 1.


*/

//sol->

#define mod 1000003

int fact(int n)
{
    if(n==0) 
        return 1;
    
    else
        return (n*fact(n-1))%mod;
}

int Solution::findRank(string A) {
    string s=A;
    int ans=0;
    int n=s.length();
    
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=i+1;j<n;j++)
        {
            if(s[j]<s[i])
                c++;
        }
        
        ans+=((c*fact(n-i-1)))%mod;
    }
    
    return (ans+1)%mod;
}


int Solution::solve(vector<int> &A, int B) {
    return countSubSeq(A, A.size(), B);
}





/*
#define mod 1000003
int fact(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return (n * fact(n - 1)) % mod;
}
int Solution::findRank(string A) {
    string s = A ;
    int ans = 0;
    int n = s.length();
    for(int i = 0; i < n-1; i++)
    {
        int count = 0;
        for(int j = i+1; j < n; j++)
            if(s[j] < s[i])
                count++;
           
        ans += (count * fact(n-i-1))%mod;
    }
    
    return (ans+1 )%mod;
}
--------------------------------
from math import factorial
class Solution:
    # @param A : string
    # @return an integer
    def findRank(self, A):
        
        res=0
        s=sorted(A)
        lna=len(A)
        e=1
        vis=set()
        for i in A:
            c=0
            for j in s:
                if j in vis:
                    continue
                if j>=i:
                    vis.add(j)
                    break
                c+=1
            res+=c*factorial(lna-e)
            e+=1
        return (res+1)%1000003
------------------------------------



*/
