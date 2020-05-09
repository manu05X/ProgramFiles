/*
Count of paths in a grid
Given an integer A, find and return the number of paths in a grid of size (A x A) that starts from (1, 1) and reaches (A, A) without crossing the major diagonal. Since the result can be large, return the result modulo (10^9 + 7). NOTE
The major diagonal of a matrix A is the collection of entries A[i][j] where i == j

Input Format
The only argument given is integer A.
Output Format
Return the number of paths modulo (10^9 + 7).
Constraints
1 <= A <= 10^6
For Example
Input 1:
    A = 2
Output 1:
    1

Input 2:
    A = 5
Output 2:
    14

*/

//sol->


#define MOD 1000000007
int Solution::solve(int A) {
    unsigned long long int ans[A+1];
    ans[0]=ans[1]=1;
        
        for(int i=2;i<=A;i++)
        {
            ans[i]=0;
            for(int j=1;j<i;j++)
            {
            ans[i]=(ans[i]%MOD+ans[j]%MOD*ans[i-j]%MOD)%MOD;
            }
            
        }
          ans[A]=ans[A]%MOD;
        return (ans[A]);
}





/*
#define ull unsigned long long
#define mod 1000000007
ull my_pow(ull val, ull power){ // Finding the mod power, in log(power) time.
    ull ans=1, mul=val;
    while (power){
        if (power&1)    ans = ans*mul%mod;
        mul = mul*mul%mod;
        power >>= 1;
    }
    return ans;
}
int Solution::solve(int A) {
    ull ans=1, i=0;
    for (i=1; i<A; i++){
        ans = (4*i - 2)*ans%mod;        // Numerator
        ans *= my_pow(i+1, mod-2);      // Denominator : We do modulo, using the idea from Fermat's little theorem
        ans %= mod;
    } 
    return ans;
}
----------------------------------

N = 2000005
    mod = 1000000007
    f=[0]*N
    fi=[0]*N
    tc=0
    
    def modexp(a,n):
        global f
        global fi
        global tc
        global N
        global mod
        r=1
        while(n):
            if(n&1):
                r=(r*a)%mod
            a=(a*a)%mod
            n>>=1
        return r
    
    
    def inv(a):
        return modexp(a,mod-2)
    
    def comb():
        global f
        global fi
        global tc
        global N
        global mod
        if(tc):
            return
        tc=1
        f[0]=f[1]=fi[0]=fi[1]=1
        for i in range(2,N):
            f[i]=(1*f[i-1]*i)%mod
        temp=inv(f[N-1])
        for i in range(N-1,0,-1):
            fi[i]=temp
            temp=(1*temp*i)%mod
    
    def ncr(n,r):
        global f
        global fi
        global tc
        global N
        global mod
        if(r>n or r<0):
            return 0
        if(r==0 or r==n):
            return 1
        if(r==1 or r==n-1):
            return n
        return (((1*f[n]*fi[r])%mod)*fi[n-r])%mod
    
    
    def nthcatalan(n):
        global f
        global fi
        global tc
        global N
        global mod
        ans=ncr(n+n,n)
        ans=(1*ans*inv(n+1))%mod
        return ans
    
    
    class Solution:
        # @param A : integer
        # @return an integer
        def solve(self, A):
            comb()
            ans=nthcatalan(A-1)
            return ans

*/
