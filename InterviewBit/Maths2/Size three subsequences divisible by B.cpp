/*
Size three subsequences divisible by B
Given an array of integers A and an integer B. Find and return the number of subsequences of length 3 whose sum is divisible by B. Since the total number of subsequences may be very large. Return the total number of subsequences of length 3 whose sum is divisible by B modulo (109+7). 
Input Format
The only argument given is the integer array A.
Output Format
Return the number of subsequences of length 3 whose sum is divisible by B modulo (10^9+7). 
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9 
1 <= B <= 10^3
For Example
Input 1:
    A = [6, 1, 1, 4, 1, 5, 3]
    B = 2
Output 1:
    20

Input 2:
    A = [4, 10, 9]
    B = 5
Output 2:
    0


*/

//sol->

int mod = 1000000007;

int countSubSeq(vector<int> A, int N, int M) 
{ 
    int ans = 0; 
  
    // Storing frequencies of all remainders 
    // when divided by M. 
    int h[M];
    
    memset(h, 0, sizeof(h));
    
    for (int i = 0; i < N; i++) { 
        A[i] = A[i] % M; 
        h[A[i]]++; 
    } 
  
    for (int i = 0; i < M; i++) { 
        for (int j = i; j < M; j++) { 
  
            // including i and j in the sum rem 
            // calculate the remainder required  
            // to make the sum divisible by M 
            int rem = (M - (i + j) % M) % M; 
  
            // if the required number is less than 
            // j, we skip as we have already calculated  
            // for that value before. As j here starts  
            // with i and rem is less than j. 
            if (rem < j) 
                continue; 
  
            // if satisfies the first case. 
            if (i == j && rem == j) 
                ans = (ans%mod + h[i] * (h[i] - 1) * (h[i] - 2) / 6)%mod; 
  
            // if satisfies the second case 
            else if (i == j) 
                ans = (ans%mod + h[i] * (h[i] - 1) * h[rem] / 2)%mod; 
  
            else if (i == rem) 
                ans = (ans%mod + h[i] * (h[i] - 1) * h[j] / 2)%mod; 
                
            else if (rem == j) 
                ans = (ans%mod + h[j] * (h[j] - 1) * h[i] / 2)%mod; 
  
            // if satisfies the third case 
            else
                ans = (ans%mod + h[i] * h[j] * h[rem])%mod; 
        } 
    } 
    return ans%mod; 
} 


int Solution::solve(vector<int> &A, int B) {
    return countSubSeq(A, A.size(), B);
}





/*
const long long mod= 1000000007;

int countsubsequences(vector<int> &a,int m){

int n=a.size();
assert(n>=1&&n<=100000);
assert(m>=1&&m<=1000);

long long cnt[m];

memset(cnt,0,sizeof cnt);

for(int i=0; i<n; ++i){
    assert(a[i]>=1 && a[i] <=1000000000);
    int y=a[i]%m;
    ++cnt[y];
}

long long ans=0;

for(int i=0; i<m; ++i){
     for(int j=i; j<m; ++j){
          int rem=(m-(i+j)%m)%m;
          if (rem<j)continue;
          if(i==j && rem==j){
             long long x=1LL*(cnt[i]*(cnt[i]-1)*(cnt[i]-2))/6;
             x%=mod;
             ans=(ans+x)%mod;
          }

         else if (i==j){
            long long x=(1LL*cnt[i]*(cnt[i]-1)*cnt[rem])/2;
            x%=mod;
            ans=(ans+x)%mod;
          }
         else if (i==rem){
            long long x=(1LL*cnt[i]*(cnt[i]-1)*cnt[j])/2;
            x%=mod;
            ans=(ans+x)%mod;
          }
        else if (j==rem){
            long long x=(1LL*cnt[j]*(cnt[j]-1)*cnt[i])/2;
            x%=mod;
            ans=(ans+x)%mod;
          }
       else{
           long long x=(1LL*cnt[j]*cnt[i]*cnt[rem]);
           x%=mod;
           ans=(ans+x)%mod;
          }
    }
}

    int anss=(int)(ans);
return anss;

}

int Solution::solve(vector<int> &A, int B) {
    return countsubsequences(A,B);
}


*/
