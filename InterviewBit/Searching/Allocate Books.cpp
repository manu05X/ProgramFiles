/*
Allocate Books
Problem Description

Given an array of integers A of size N and an integer B.

College library has N books,the ith book has A[i] number of pages.

You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
Calculate and return that minimum possible number.



NOTE: Return -1 if a valid assignment is not possible.



Problem Constraints
1 <= N <= 105
1 <= A[i], B <= 105



Input Format
The first argument given is the integer array A.
The second argument given is the integer B.



Output Format
Return that minimum possible number



Example Input
A = [12, 34, 67, 90]
B = 2


Example Output
113


Example Explanation
There are 2 number of students. Books can be distributed in following fashion : 
        1) [12] and [34, 67, 90]
        Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
        2) [12, 34] and [67, 90]
        Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
        3) [12, 34, 67] and [90]
        Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages
        Of the 3 cases, Option 3 has the minimum pages = 113.
 
*/

bool isPossible(vector<int>&A,long long int X, int B)
{
    int n=A.size();
    long long int sum=X;
    int stdcnt =1,i=0;
    
    while(i<n)
    {
        if(sum-A[i]<0)
        {
            stdcnt++;
            sum=X;
        }
        
        else
        {
            sum-=A[i];
            i++;
        }
        
        if(stdcnt>B)
            return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    if(n<B) 
        return -1;
        
    long long int pages=0;
    for(int i=0;i<n;i++)
        pages+=A[i];
        
    long long int low=0,high=pages;
    long long int mid,ans=-1;
    
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(isPossible(A,mid,B))
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}


/*

public class Solution {
	public int books(ArrayList<Integer> A, int B) {
	    
	    int students = B;
	    long high = Long.MAX_VALUE;
	    long low = 0;
	    long mid, res = 0;
	    
	    if (B > A.size())
	        return -1;
	    
	    long sum = 0;
	    
	    for (int pages : A)
	        sum += pages;
	    
	    while (low <= high) {
	        
	        mid = low + ((high - low) >> 1);
	        
	        if (isPossible(A, B, mid, sum)) {
	            res = mid;
	            high = mid - 1;
	        } else {
	            low = mid + 1;
	        }
	    }
	    
	    return (int) res;
	    
	}
	
	private boolean isPossible(ArrayList<Integer> A, int B, long maxPage, long totalPages) {
	    
	    if (maxPage < totalPages / B)
	        return false;
	    
	    int index = 0;
	    int n = A.size();
	    int i;
	    
	    for (i = 0; i < B && index < n; i++) {
	        long page = maxPage;
	        long total = 0;
	        
	        while (total < maxPage && index < n) {
	            total += A.get(index);
	            if (total > maxPage)
	                break;
	            index++;
	        }
	    }
	    
	    if (index < n)
	        return false;
	    
	    return true;
	}
	
}

*/
