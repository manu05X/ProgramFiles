#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
     //int sum=0;
        long long n,sum=0;
        cin>>n;
        while(n!=0){
            sum=sum+n%10;
            n=n/10;
        }
        cout<<sum<<endl;
	// Write your code here
}
}
