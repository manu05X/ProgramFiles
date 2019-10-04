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
