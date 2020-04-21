/*
Segmented Sieve Problem
Send Feedback
In this problem you have to print all primes from given interval.
Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].
Output
For each test case output must contain all primes from interval [L; U] in increasing order.
Sample Input:
2
2 10
3 7
Sample Output:
2
3
5
7
3
5
7 
*/

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
void calculate_primes(vector<int>& primes); //Helper Function to calculate primes from 1 to 32000
int main()
{
    vector<int> primes(32001,1); // An array which holds the list of primes from 1 to 32000 (1 for prime, 0 for composite)
    calculate_primes(primes); 
    int cases;
    cin >> cases;
    for(int t=0;t<cases;t++)
    {
        long long int m,n,i,j;
        cin >> m >> n;
        vector<int> sieve(n-m+1,1); // A sieve or a boolean array that stores the list of primes from m to n (1 for prime, 0 for composite)
        for(i=2;i<=32000;i++)
        {
            /* Proceed only if i is prime*/
            if(primes[i]==1)
            {
                /* If m is divisible by, we start j from m/i , else from the next value*/
                if(m%i == 0)
                {
                    j = m/i;
                }
                else{
                    j = m/i + 1;
                }
                /* Very Critical Case: If j comes out to be 1, or less than i*/
                if( j < i)
                {
                    j = i;
                }
 
                long long int temp = j*i;
                while(temp<=n)
                {
                    sieve[temp-m]=0;
                    j++;
                    temp = j*i;
                }
            }
        }
 
        if(m == 1)
        {
            sieve[0] = 0; // 1 is always composte
        }
 
        for(i=0;i<n-m+1;i++)
        {
            if(sieve[i]==1)
                printf("%ld\n",m+i);
        }
    }
}
 
void calculate_primes(vector<int>& primes)
{
    primes[0]=0;
    primes[1]=0;
    for(long long int i=2;i<=32000;i++)
    {
        long long int j = i;
        long long int temp = j*i;
        while(temp <= 32000)
        {
            primes[temp] = 0;
            j++;
            temp = j*i;
        }
    }
} 