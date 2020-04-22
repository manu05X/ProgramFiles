/*
DIVISIONS

Given an array of integers A of size N and an integer B.

Power of a subarray = (Number of set bits in all elements of subarray) X (size of subarray).

Divide array A in atmost B subarrays such that sum of power of all subarrays is minimum.

Return minimum possible sum of power of all subarrays.



Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return minimum possible sum of power of all subarrays.
Constraints

1 <= N <= 1000
0 <= A[i] <= 100000
1 <= B <= 100
For Example

Example Input 1:
    A = [11, 11, 11, 24]
    B = 2
Example Output 1:
    22
Example Explanation 1:
    11 = 01011 (set bits = 3)
    24 = 11000 (set bits = 2)
    
    Optimal division = [11, 11], [11, 24]
    size of subarray 1 = 2
    size of subarray 2 = 2
    power = (size of subarray 1) * (set bits in subarray 1) + (size of subarray 2) * (set bits in subarray 2)
    
    power = 2 * (3 + 3) + 2 * (3 + 2) = 22
Input 2:
    A = [8, 3, 5, 1]
    B = 1
Output 2:
    24
Explanation 2:
    Only possible division = [8, 3, 5, 1]
    8 = 1000 (set bits = 1)
    3 = 0011 (set bits = 2)
    5 = 0101 (set bits = 2)
    1 = 0001 (set bits = 1)
    
    Number of set bits = 6
    Size of subarray = 4
    
    Power = 6 * 4 = 24
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007LL
#define ll long long
#define infinity 1111111111111111111ll

ll C[1111];
ll X[1111];
ll F[111][1111];
int Solution :: solve(vector <int> &A, int B)
{
    memset(F, 0, sizeof F);
    memset(X, 0, sizeof X);
    memset(C, 0, sizeof C);

    int G = B, L = A.size();

    for (int i = 1; i <= L; i++) {
        C[i] = A[i-1];
     }
    for(int i = 1;i<=L;i++)
    {
        int temp = C[i],cnt = 0;
        while(temp)
        {
            if(temp%2)
            {
                cnt++;
            }
            temp /= 2;
        }
        X[i] = cnt;
    }

    for(int i = 2; i <= L; i++)
    {
        X[i] += X[i-1];
    }

    #define cost(i,j) (X[j] - X[i-1])*((j)-(i)+1)

    for (int g = 1; g <= G; g++) {
        for (int l = 0; l <= L; l++) {
            if (g == 1) {
                F[g][l] = cost(1,l);
            } else {
                F[g][l] = infinity;
                for (int k = 0; k <= l; k++) {
                    ll new_cost = F[g-1][k] + cost(k+1,l);
                    if (F[g][l] > new_cost) F[g][l] = new_cost;
                }
            }
        }
    }
    return F[G][L];
}