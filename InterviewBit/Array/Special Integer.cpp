/*
Special Integer
Problem Description

Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with sum of elements greater than B.



Problem Constraints
1 <= |A| <= 100000
1 <= A[i] <= 10^9

1 <= B <= 10^9



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the maximum value of K (sub array length).



Example Input
Input 1:

A = [1, 2, 3, 4, 5]
B = 10
Input 2:

A = [5, 17, 100, 11]
B = 130


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

Constraints are satisfied for maximal value of 2.
Explanation 2:

Constraints are satisfied for maximal value of 3.


*/

//sol->

#define mkp make_pair
#define pb push_back
#define scan(x) scanf("%d", &x)
#define ll long long int
#define MOD 1000000007
#define pii pair<int, int>

int Solution::solve(vector<int> &arr, int x) 
{
    
    ll n, i, j, k, a, b, c, y, z, ans;
    ll start, mid, end;
    n = arr.size();
    k = 0;
    start = 0; 
    end = n;
    ll s;
    while (start <= end) {
        mid = start + (end - start) / 2;
        s = 0;
        for (i = 0; i < mid; ++i) {
            s += arr[i];
            if (s > x) {
                break;
            }
        }
        if (s <= x) {
            for (i = mid; i < n; ++i) {
                s -= arr[i-mid];
                s += arr[i];
                if (s > x) break;
            }
        }
        
        if (s > x) {
            end = mid-1;
        } else {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

/*
int Solution::hammingDistance(const vector<int> &A) {
    int inputSize = A.size();
    int mod = 1000000007;
    int sum = 0;
    for (int bitPosition = 0; bitPosition < 31; bitPosition++) {
        int cntBitOne = 0, cntBitZero = 0;
        for(int i = 0; i < inputSize; i++) {
            if (A[i] & (1 << bitPosition)) cntBitOne++;
            else cntBitZero++;
        }
        sum = sum + ((2LL * cntBitOne * cntBitZero) % mod);
        if (sum >= mod) sum = sum - mod;
    }
    return sum;
}

*/