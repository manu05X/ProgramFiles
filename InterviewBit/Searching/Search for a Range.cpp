/*
Search for a Range
Problem Description

Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm's runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].



Problem Constraints
1 <= N <= 106

1 <= A[i], B <= 109



Input Format
The first argument given is the integer array A.
The second argument given is the integer B.



Output Format
Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].



Example Input
Input 1:

 A = [5, 7, 7, 8, 8, 10]
 B = 8
Input 2:

 A = [5, 17, 100, 111]
 B = 3


Example Output
Output 1:

 [3, 4]
Output 2:

 [-1, -1]


Example Explanation
Explanation 1:

 First occurence of 8 in A is at index 3
 Second occurence of 8 in A is at index 4
 ans = [3, 4]
Explanation 2:

 There is no occurence of 3 in the array.
 
 
 
*/

int binarySearch(const vector<int>&A,int key,bool searchFirst)
{
    int start =0;
    int end=A.size()-1;
    int mid;
    int result=-1;
    
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(A[mid]==key)
        {
            result=mid;
            if(searchFirst)
                end=mid-1;
                
            else
                start=mid+1;
                
        }
        else if(A[mid]>key)
            end=mid-1;
            
        else
            start=mid+1;
    }
    return result;
}


vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int>sol;
    sol.push_back(binarySearch(A,B,true));
    sol.push_back(binarySearch(A,B,false));
    
    return sol;
}


/*

vector<int>Solution::searchRange(const vector<int> &A, int target) {
    int n = A.size();
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;

    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;   // Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;               // So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}


public class Solution {
	// DO NOT MODIFY THE LIST
	public ArrayList<Integer> searchRange(final List<Integer> A, int B) {
	    
	    int low, up;
	    ArrayList<Integer> res = new ArrayList<>();
	    
	    low = lowerBound(A, 0, A.size() - 1, B);
	    
	    if (low == -1) {
	        res.add(-1);
	        res.add(-1);
	        return res;
	    }
	       
	   up = upperBound(A, 0, A.size() - 1, B);
	   
	   res.add(low);
	   res.add(up);
	   
	   return res;
	    
	    
	}
	
	public int lowerBound(final List<Integer> A, int start, int end, int num) {
	    
	    int steps = end - start + 1;
	    int mid;
	    int low = -1;
	    int val;
	    
	    while (steps > 0) {
	        
	        mid = (start + end) / 2;
	        val = A.get(mid);
	        
	        if (num < val) {
	            end = mid - 1;
	        } else if (num > val) {
	            start = mid + 1;
	        } else {
	            low = mid;
	            end = mid - 1;
	        }
	        
	        steps /= 2;
	    }
	    
	    return low;
	    
	}
	
	public int upperBound(final List<Integer> A, int start, int end, int num) {
	    
	    int steps = end - start + 1;
	    int mid;
	    int up = end + 1;
	    int val;
	    
	    while (steps > 0) {
	        
	        mid = (start + end) / 2;
	        val = A.get(mid);
	        
	        if (num < val) {
	            end = mid - 1;
	        } else if (num > val) {
	            start = mid + 1;
	        } else {
	            up = mid;
	            start = mid + 1;
	        }
	        
	        steps /= 2;
	    }
	    
	    return up;
	    
	}
}

class Solution:
    # @param A : tuple of integers
    # @param B : integer
    # @return a list of integers
    def searchRange(self, A, B):
        n = len(A)
        low = 0
        high = n-1
        firstOcc = -1
        while low <= high:
            mid = (low+high)//2
            if A[mid] == B:
                firstOcc = mid
                high = mid - 1
            elif A[mid] < B:
                low = mid + 1
            else:
                high = mid - 1
        if firstOcc == -1:
            return [-1,-1]
        low = firstOcc
        high = n-1
        secondOcc = -1
        while low <= high:
            mid = (low+high)//2
            if A[mid] == B:
                secondOcc = mid
                low = mid + 1
            elif A[mid] < B:
                low = mid + 1
            else:
                high = mid - 1
        return [firstOcc, secondOcc]

*/
