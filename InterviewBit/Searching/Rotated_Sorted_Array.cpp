/*
Rotated Sorted Array Search

Given a sorted array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.



Problem Constraints
1 <= N <= 1000000

1 <= A[i] <= 10^9

all elements in A are disitinct.



Input Format
The first argument given is the integer array A.

The second argument given is the integer B.



Output Format
Return index of B in array A, otherwise return -1



Example Input
Input 1:

A = [4, 5, 6, 7, 0, 1, 2, 3]
B = 4
Input 2:

A = [1]
B = 1


Example Output
Output 1:

 0
Output 2:

 0


Example Explanation
Explanation 1:

 
Target 4 is found at index 0 in A.
Explanation 2:

 
Target 1 is found at index 0 in A.
 
 
*/

int search2(const vector<int>&A,int l,int h,int key)
{
    if(l>h) return -1;
    
    int mid=(l+h)/2;
    if(A[mid]==key)
        return mid;
        
    if(A[l]<=A[mid])
    {
        
        if(key>=A[l] && key<=A[mid])
            return search2(A,l,mid-1,key);
            
        return search2(A,mid+1,h,key);
    }
    
    if(key>=A[mid]&& key<=A[h])
        return search2(A,mid+1,h,key);
        
    return search2(A,l,mid-1,key);
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
   int n=A.size();
   int i=search2(A,0,n-1,B);
   return i;
}
