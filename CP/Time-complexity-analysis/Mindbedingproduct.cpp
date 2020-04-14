/*
Mindbending Product

You are given an array A of size N, You have to construct a product array P(of same size) such that P is equal 
to the product of all the elements of A except A[i]. The constraint is that you are not allowed to use division operator. Also
you have to do in constant space complexity.

Input
2
5
10 3 5 6 2
2
12 20

output
180 600 360 300 900
20 12

*/


#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		long prod[n];
		
		for(int i =0; i<n;i++){
			cin>>arr[i];
		}
		long lp =1;
		for(int i =0; i<n;i++){
			prod[i]=lp;
			lp = lp*arr[i];
		}
		long rp =1;
		for(int i =n-1; i>=0;i--){
			prod[i] = prod[i]*rp;
			rp = rp*arr[i];
		}
		for(int i =0; i<n;i++){
			cout<<prod[i]<<" ";
		}
		cout<<endl;		
	}
	return 0;
}


/*int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	int* arr=new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	long double sum=0;

	for (int i = 0; i < n; ++i)
	{
		sum+=(long double)log10(arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << int(pow((long double)10.00, sum-log10(arr[i]))) << " ";
	}



	return 0 ; 

}*/
