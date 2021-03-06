/*
Different Bits Sum Pairwise

We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111,respectively. The first and the third bit differ, so f(2, 7) = 2. You are given an array of N positive integers, A1, A2 ,..., AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.       


Problem Constraints
  
1 <= N <= 100000
1 <= A[i] <= INTMAX
       


Input Format
First and only argument of input contains a single integer array A.


Output Format
Return a single integer denoting the sum.


Example Input
Input 1:
A = [1, 3, 5]
       


Example Output
Ouptut 1:
8
       


Example Explanation
Explanation 1:
 f(1, 1) + f(1, 3) + f(1, 5) + f(3, 1) + f(3, 3) + f(3, 5) + f(5, 1) + f(5, 3) + f(5, 5) 
= 0 + 1 + 1 + 1 + 0 + 2 + 1 + 2 + 0

*/

//sol->

int Solution::cntBits(vector<int> &A) {
    unsigned long long mod=1000000007;
    unsigned long long res=0;
    int n=A.size();
    for(int i=0;i<32;i++)
    {
        unsigned long long sum=0;
        for(int j=0;j<A.size();j++)
        {
            if((A[j] & (1<<i)))
            sum++;
        }
        res=res+(sum*(n-sum)*2);
    }
    res=res%mod;
    return res;
}





/*
typedef long long LL;
#define MOD 1000000007ll
int Solution::cntBits(vector<int> &A) {
    int ans=0,n=A.size();

    //traverse over all bits
    for(int i=0; i<31; i++){

        //count number of elements with ith bit = 0
        LL cnt=0;
        for(int j=0; j<n; j++)
            if((A[j]&(1<<i)))cnt++;

        //add to answer cnt*(n-cnt)*2
        ans += (cnt*((LL)n-cnt)*2)%MOD;
        if(ans>=MOD)ans-=MOD;

    }

    return ans;
}

*/