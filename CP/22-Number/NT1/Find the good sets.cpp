/*
Find the good sets!
Send Feedback
You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. You can use one value only once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.
Input
First line of the input contains an integer T denoting the number of test cases. T test cases follow.

First line of each test case contains an integer n denoting number of elements in array a.

Next line contains n space separated integers denoting the elements of array a.
Output
For each test case, output a single line containing the corresponding answer.
Constraints
1 ≤ T ≤ 3

1 ≤ n ≤ 7.5 * 10^5

1 ≤ ai ≤ 7.5 * 10^5

All the elements of array a are distinct.
Example
Input
2
2
1 2
3
6 2 3
Output:
3
5
Explanation
Test case 1. There are three sets which are good {1}, {2}, {1, 2}.

Test case 2. There are five sets which are good {6}, {2}, {3}, {6 2}, {6, 3}.
*/

#include <stdio.h>
#include <string.h>
#define M 750000
#define MOD 1000000007
 
int inp[M+1], dp[M+1];
 
int main() {
  int t,n,sum;
  scanf("%d", &t);
  while(t--) {
    sum = 0;
    memset(inp, 0, sizeof(inp));
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0, j; i < n; ++i) {
      scanf("%d", &j);
      inp[j] = 1;
    }
    for(int i = 1; i <= M; ++i) {
      if(inp[i]) {
        dp[i] = (dp[i] + 1) % MOD;
        sum = (sum + 1) % MOD;
        for(int j = 2 * i; j <= M; j += i) {
          if(inp[j]) {
            dp[j] = (dp[j] + dp[i]) % MOD;
            sum = (sum + dp[i]) % MOD;
          }
        }
      }
    }
    printf("%d\n", sum);
  }
 return 0;
}