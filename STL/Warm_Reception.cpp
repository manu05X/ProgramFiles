/*
Warm Reception
Send Feedback
There is only one beauty parlour in the town CodingNinjasLand. The receptionist at beauty parlour is flooded with appointment requests because “Hakori” festival is round the corner and everyone wants to look good on it.
S/he needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell minimum number of chairs required such that none of the customer has to stand.
Input Format :
First line contains number of customers that will come. Second line contains N space separated integers which represent arrival timings of the customer. Third line contains N space separated integers which represent departure timings of the customer. Arrival and departure timings are given in 24 hour clock.
Constraints:
1<= N <= 100
Arrival and departure timings lie in the range [0000 to 2359]
Time Limit: 1 second
Output Format :
You have to print the minimum number of chairs required such that no customer has to wait standing. 
Sample Test Cases:
Sample Input 1 :
5
900 1000 1100 1030 1600
1900 1300 1130 1130 1800
Sample Output 1:
4
Explanation:
4 because at 1100 hours, we will have maximum number of customers at the shop, throughout the day. And that maximum number is 4. 
*/

#include<bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const int maxTime=2400;
    int n; cin >> n;
    int arrival[n], departure[n];
    for (int i = 0; i < n; i++) cin >> arrival[i];
    for (int i = 0; i < n; i++) cin >> departure[i];
    vector<int> a(maxTime,0);
    for(int i=0;i<n;i++){
        a[arrival[i]]++;
        a[departure[i]]--;
    }
    int max1=0;
    for(int i=0;i<maxTime;i++){
           a[i]=a[i-1]+a[i];
           max1=max(max1,a[i]);
    }
    
     cout << max1 << endl;
    return 0;
}