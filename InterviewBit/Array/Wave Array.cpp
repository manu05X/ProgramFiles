/*
Wave Array
Problem Description
Given an array of integers A, sort the array into a wave like array and return it, In other words, arrange the elements into a sequence such that a1 &gt;= a2 &lt;= a3 &gt;= a4 &lt;= a5..... NOTE : If there are multiple answers possible, return the one that's lexicographically smallest.  


Problem Constraints
1 <= len(A) <= 106
1 <= A[i] <= 106


Input Format
First argument is an integer array A.


Output Format
Return an array arranged in the sequence as described.


Example Input
Input 1:
A = [1, 2, 3, 4]
 


Example Output
Output 1:
[2, 1, 4, 3]
 


Example Explanation
Explanation 1:
One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
First answer is lexicographically smallest. So, return [2, 1, 4, 3].
*/

//sol->

void swap(int &a,int &b)
{
    int t = a;
    a=b;
    b=t;
}

vector<int> Solution::wave(vector<int> &A) {
    
    sort(A.begin(),A.end());
    int n =A.size();
    if(A.size()%2 !=0)
    {
        n=A.size()-1;
    }
    for(int i=0;i<n;i=i+2)
    {
        swap(A[i],A[i+1]);
    }
    return A;
}


/*
public class Solution {
	public ArrayList<Integer> wave(ArrayList<Integer> A) {
	    
	    Collections.sort(A);
	    int n = A.size();
	    
	    for (int i = 2; i <= n; i += 2) {
	        exch(A, i - 2, i - 1);
	    }
	    
	    return A;
	    
	}
	
	private void exch(ArrayList<Integer> A, int i, int j) {
	    int temp = A.get(i);
	    A.set(i, A.get(j));
	    A.set(j, temp);
	}
	
}
*/