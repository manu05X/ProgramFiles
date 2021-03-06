/*
Minimize the absolute difference
Given three sorted arrays A, B and Cof not necessarily same sizes. Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively. i.e. minimize | max(a,b,c) - min(a,b,c) |. Example : Input:
A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:
1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i=A.size()-1,j=B.size()-1,k=C.size()-1;
    
	int cur_min=INT_MAX;

	while(i!=-1 && j!=-1 && k!=-1)
	{
		int cur_value=max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k]));
    
		if(cur_value<cur_min)
			cur_min=cur_value;
     
		int cur_max=max(A[i],max(B[j],C[k]));
		if(cur_max==A[i])
			i-=1;
     
		else if(cur_max==B[j])
			j-=1;
     
		else
			k-=1;
	}
	return cur_min;
}
