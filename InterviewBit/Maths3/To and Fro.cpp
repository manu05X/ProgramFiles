/*
To and Fro
Problem Description
The Guardians of the Galaxy have just landed on Earth. There are N cities in a row numbered from 1 to N. The cost of going from a city with number i to a city with number j is the remainder when (i+j) is divided by (n+1). The Guardians want to visit every city but in the minimum cost. What is the minimum cost that will be incurred? 


Problem Constraints
1 <= N <= 10000000


Input Format
A single integer N denoting the number of cities.


Output Format
Minimum cost to be able to travel to each city


Example Input
 3


Example Output
 1


Example Explanation
 Tour would be 1 -> 3 -> 2.
 
*/

//sol->

int Solution::solve(int A) {
    if(A%2==0)
        return((A/2)-1);
    else 
        return(A/2);
        
    
}






/*
int Solution::solve(int A) {
    int n;
	    n=A;
	    int ans;
	    if(n%2!=0)
	        ans=(n-1)/2;
	    else
	    {
	        ans=(n/2)-1;
	    }
	    return ans;

}
--------------------
public class Solution {
    public int solve(int A) {
        return (A-1)/2;
    }
}
----------------------
class Solution:
    def solve(self, A):
        return ((A-1)//2)
*/
