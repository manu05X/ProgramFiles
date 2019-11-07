#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    int arr[n+1] = {0}, ans[n+1] = {0};
    int m; cin >> m;
    while(m--) {
        int l, r; cin >> l >> r;
        arr[l] ++; arr[r+1] --;
    }
    for(int i=1; i<=n; i++) {
        arr[i] += arr[i-1];
        ans[arr[i]] ++;
    }
    for(int i=n-1; i>0; i--) ans[i] += ans[i+1];
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}
