/*
ALL GCD
Given an array of integers A of size N. Find and return how many distinct gcd( sub(A) ) values are possible, where sub(A) is any non-empty subsequence of arraya A. NOTE: gcd here refers to greatest common divisor. 
Input Format
The first argument given is the integer array A.
Output Format
Return how many distinct gcd( sub(A) ) values are possible, where sub(A) is any subsequence of array A.
Constraints
1 <= N <= 1000
1 <= A[i] <= 1000
For Example
Input 1:
    A = [3, 2, 8]

Output 1:
    4
Explaination 1:
gcd([3]) = 3
gcd([3, 2]) = 1
gcd([3, 8]) = 1
gcd([2]) = 2
gcd([2, 8]) = 2
gcd([8]) = 8
gcd([3, 2, 8]) = 1
There are 4 distinct gcd values (1,2, 3, 8).

Input 2:
    A = [5, 17, 3, 11]
Output 2:
    5


*/

//sol->


int Solution::solve(vector<int> &A) 
{
   bool ans[10001];
   int n=A.size();
   for(int i=0;i<10001;i++)
   {
       ans[i]=false;
   }
   
   for(int i=0;i<n;i++)
   {
       vector<int>v;
       v.push_back(A[i]);
       for(int j=1;j<=10000;j++)
       {
           if(ans[j])
           {
               v.push_back(__gcd(A[i],j));
           }
       }
       for(int j=0;j<v.size();j++)
       {
           ans[v[j]]=true;
       }
   }
   int fans=0;
   for(int i=0;i<10000;i++)
   {
       if(ans[i])
       {
           fans++;
       }
   }
   return fans;
}





/*
int Solution::solve(vector <int> A)
{
    bool ans[10001];
    int n  = A.size();
    for(int i=0;i<10001;i++)
    {
        ans[i] = false;
    }
    for(int i = 0;i < n;i++)
    {
        vector <int> v;
        v.push_back(A[i]);
        for(int j=1;j<=10000;j++)
        {
            if(ans[j])
            {
                v.push_back(__gcd(A[i], j));
            }
        }
        for(int j=0;j<v.size();j++)
        {
            ans[v[j]] = true;
        }
    }
    int fans = 0;
    for(int i=0;i<=10000;i++)
    {
        if(ans[i])
        {
            fans++;
        }
    }
    return fans;
}
*/
