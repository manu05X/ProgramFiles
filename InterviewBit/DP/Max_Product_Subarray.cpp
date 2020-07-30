/*
Max Product Subarray
Problem Description

Given an integer array A of size N. Find the contiguous subarray within the given array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

NOTE: Answer will fit in 32-bit integer value.



Problem Constraints
1 <= N <= 5 * 105

-100 <= A[i] <= 100



Input Format
First and only argument is an integer array A.



Output Format
Return an integer corresponding to the maximum product possible.



Example Input
Input 1:

 A = [4, 2, -5, 1]
Input 2:

 A = [-3, 0, -5, 0]


Example Output
Output 1:

 8
Output 2:

 0


Example Explanation
Explanation 1:

 We can choose the subarray [4, 2] such that the maximum product is 8.
Explanation 2:

 0 will be the maximum product possible.
 
*/

int Solution::maxProduct(const vector<int> &A) {
    int minVal=A[0];
    int maxVal=A[0];
    
    int maxProduct=A[0];
    
    for(int i=1;i<A.size();i++)
    {
        if(A[i]<0)
            swap(maxVal,minVal);
            
        maxVal=max(A[i],maxVal*A[i]);
        minVal=min(A[i],minVal*A[i]);
        
        maxProduct=max(maxProduct,maxVal);
    }
    return maxProduct;
}





/*
int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    // store the result that is the max we have found so far
    long long r = A[0];
    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (long long i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i] * 1LL, imax * A[i]);
        imin = min(A[i] * 1LL, imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
        
    }
    return r;
}
*/
