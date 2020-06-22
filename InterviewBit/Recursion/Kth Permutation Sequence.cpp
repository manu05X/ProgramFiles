/*
Kth Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

 Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
 In this case, just concatenate the number to the answer. so if n = 11, k = 1, ans = "1234567891011" 
Whats the maximum value of n and k?
 In this case, k will be a positive integer thats less than INT_MAX. n is reasonable enough to make sure 
 the answer does not bloat up a lot. 

*/

//sol->


int fact(int n)
{
    if(n>12)
        return INT_MAX;
    int f=1;
    for(auto i=2;i<=n;i++)
        f*=i;
    return f;
}
string backtracking(int k,vector<int>& numlist)
{
    auto n=numlist.size();
    if(n==0 || k>fact(n))
        return "";
    int f=fact(n-1);
    int pos=k/f;
    k%=f;
    string ch=to_string(numlist[pos]);
    numlist.erase(numlist.begin()+pos);
    return ch+backtracking(k,numlist);
}

string Solution::getPermutation(int n, int k) {
    vector<int>numlist;
    
    for(auto i=1;i<n+1;i++)
        numlist.emplace_back(i);
    return backtracking(k-1,numlist);
}





/*
public class Solution {
	public String getPermutation(int A, int B) {
	ArrayList<Integer> candidateSet = new ArrayList<>();
        for (int i = 1; i <= A; i++){
            candidateSet.add(i);
        }
        return getPermutation(B - 1, candidateSet);
    }

    private static String getPermutation(int k, ArrayList<Integer> candidateSet) {
        int n = candidateSet.size();
        if (n == 0) {
            return "";
        }
        if (k > factorial(n)) return ""; // invalid. Should never reach here.

        int f = factorial(n - 1);
        int pos = k / f;
        k %= f;
        String ch = String.valueOf(candidateSet.get(pos));
        // now remove the character ch from candidateSet.
        candidateSet.remove(pos);
        return ch + getPermutation(k, candidateSet);
    }

    static int factorial(int n) {
        if (n > 12) {
            // this overflows in int. So, its definitely greater than k
            // which is all we care about. So, we return INT_MAX which
            // is also greater than k.
            return Integer.MAX_VALUE;
        }
        // Can also store these values. But this is just < 12 iteration, so meh!
        int fact = 1;
        for (int i = 2; i <= n; i++) fact *= i;
        return fact;
    }
}


----------------------------------

import math
class Solution:
    def getP(self,strs,st,n,k,nf):
        if k==0 or st>n-1:
            return
        else:
            l=k/math.factorial(n-st-1)
            p=strs.pop(st+l)
            strs.insert(st,p)
            k=k%math.factorial(n-st-1)
            self.getP(strs,st+1,n,k,nf)
        return
     
    # @return a string
    def getPermutation(self, n, k):
        strs = [str(x) for x in range(1,n+1)]
        nf=[1,1,2,6,24,120,720,5040,40320,362880, 3628800, 39916800]
        st=0
        k=k-1
        self.getP(strs,st,n,k,nf)
        return "".join(x for x in strs)

*/
