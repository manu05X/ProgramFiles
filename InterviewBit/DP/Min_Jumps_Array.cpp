/*
Min Jumps Array
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Return the minimum number of jumps required to reach the last index. If it is not possible to reach the last index, return -1. Input Format:
The first and the only argument contains an integer array, A.
Output Format:
Return an integer, representing the answer as described in the problem statement.
Constraints:
1 <= N <= 1e6
0 <= A[i] <= 50000
Examples:
Input 1:
    A = [2, 1, 1]

Output 1:
    1

Explanation 1:
    The shortest way to reach index 2 is
        Index 0 -> Index 2
    that requires only 1 jump.

Input 2:
    A = [2,3,1,1,4]

Output 2:
    2

Explanation 2:
    The shortest way to reach index 4 is
        Index 0 -> Index 1 -> Index 4
    that requires 2 jumps.
*/

int Solution::jump(vector<int> &A) 
{
    /*int n = A.size();
    int *jumps = new int[n]; // jumps[n-1] will hold the result for min jump
    int i, j; 
  
    // Base case: when source and 
    // destination are same 
    if (n == 1) 
        return 0; 
  
    if (n == 0 || A[0] == 0) 
        return -1; 
  
    jumps[0] = 0; // 0 jumps are needed to reach the 0 index
  
    // Find the minimum number of jumps to reach arr[i] 
    // from arr[0], and assign this value to jumps[i] 
    for (i = 1; i < n; i++) 
    { 
        jumps[i] = INT_MAX;     // intialize it to +infinite
        for (j = 0; j < i; j++) 
        { 
            if (i <= j + A[j] ) // condition to check if i is in range of j
            {                                            //minimum of original or previous (jump[i])
                jumps[i] = min(jumps[i], jumps[j] + 1);  // and value from jump (jumps[j] + 1)
                break; 
            } 
        } 
    } 
    return jumps[n - 1];*/
 // ***************************************************************************************** 
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    
    if(n==1) 
        return 0;
    
    int max_reach=A[0],step=A[0],jump=1;
    
    for(int i=1;i<n-1;i++){
        max_reach = max(max_reach,i+A[i]);
        step--;
        if(step<0) 
            return -1;
        if(step==0)
        {
         jump++;
         step=max_reach-i; 
        }
    }
    if(max_reach>=n-1) return jump;
    return -1;
    
    
}
