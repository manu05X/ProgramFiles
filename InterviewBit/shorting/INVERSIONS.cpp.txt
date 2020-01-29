/*
INVERSIONS
Given an array A, count the number of inversions in the array. Formally speaking, two elements A[i] and A[j] form an inversion if A[i] > A[j] and i < j Example:
A : [2, 4, 1, 3, 5]
Output : 3
as the 3 inversions are (2, 1), (4, 1), (4, 3).
*/

long long merge(vector<int> &A,int left,int mid,int right){

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
long long merge_sort(vector<int> &A,int left,int right){

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
long long solve(vector<int> &A, long long n)
{
	long long ans = merge_sort(A,0,n-1);
	return ans;
}
int Solution::countInversions(vector<int> &A) 
{
    long long n = A.size();
    solve(A,n);
}
