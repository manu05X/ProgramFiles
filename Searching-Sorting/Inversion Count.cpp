/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
				PROBLEM STATEMENT
Let A[0 ... n-1] be an array of n distinct positive integers. 
If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A 
(where i and j are indexes of A). Given an integer array A, your task is to
 find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9

*/

#include <bits/stdc++.h>

using namespace std;

long long merge(int A[],int left,int mid,int right){

	int i=left,j=mid,k=0;

	int temp[right-left+1];
	long long count = 0;
	while(i<mid && j<=right){
		if(A[i] <= A[j]){
			temp[k++] = A[i++];
		}else{
			temp[k++] = A[j++];
			count += mid - i;
		}
	}
	while(i<mid){
		temp[k++] = A[i++];
	}
	while(j<=right){
		temp[k++] = A[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++){
		A[i] = temp[k];
	}
	return count;
}
long long merge_sort(int A[],int left,int right){

	long long count = 0;
	if(right > left){
		int mid = (left + right)/2;

		long long countLeft = merge_sort(A,left,mid);
		long long countRight = merge_sort(A,mid+1,right);
		long long myCount = merge(A,left,mid+1,right);

		return myCount + countLeft + countRight;
	}
	return count;

}
long long solve(int A[], int n)
{
	long long ans = merge_sort(A,0,n-1);
	return ans;
}


#define MAXN 100005

int main()
{
	int n,A[MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		cin>>A[i];
	}
	cout<<solve(A,n)<<endl;
}


/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

  
ll merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int i, j, k; 
    ll inv_count = 0; 
  
    i = left;
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
  	while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  	for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
ll zmergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid;
    ll inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count = zmergeSort(arr, temp, left, mid); 
        inv_count += zmergeSort(arr, temp, mid + 1, right); 
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 


ll mergeSort(int arr[], int array_size) 
{ 
    int* temp = (int*)malloc(sizeof(int) * array_size); 
    return zmergeSort(arr, temp, 0, array_size - 1); 
} 

long long solve(int A[], int n)
{
  return mergeSort(A,n);
}

/*
int main() {
	ll t;
  cin>>t;
  ll arr[t];
  for(ll i = 0;i<t;i++){
    cin>>arr[i];
  }
  ll inv_count = 0;
  inv_count = mergeSort(arr,t);
  cout<<inv_count<<endl;
  return 0;
}*/
*/
