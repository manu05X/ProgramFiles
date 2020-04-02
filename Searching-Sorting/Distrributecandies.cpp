/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies 
(between 1 and 1000000000). 
Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students.
 He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. 
Help Shaky in finding out what is the maximum number of candies which a student can get.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

 bool func(ll a[],ll val,ll k,ll n)
{
    if(k==1)
        return true;
    ll sum=0;
    for(ll i=n-1;i>=0;i--)
    {
        sum +=(a[i]/val);
    }
    if(sum >= k)
        return true;
    else
        return false;
}
void binary_search(ll a[],ll n,ll k)
{
    ll lo =1;
    ll high =a[n-1]+1;
    ll mid=0;
    while(high > lo)
    {
         mid = (lo+high)/2;
        if(func(a,mid,k,n))
            lo = mid+1;
        else
            high = mid;
    }
    cout<<lo-1<<endl;
}

int main() {
	ll t;
  cin>>t;
  while(t--){
    ll n,k;
    cin>>n>>k;
    ll ar[500010];
    
    for(ll i = 0;i<n;i++){
      cin>>ar[i];
    }
    sort(ar,ar+n);
    binary_search(ar,n,k);
  }
  return 0;

}