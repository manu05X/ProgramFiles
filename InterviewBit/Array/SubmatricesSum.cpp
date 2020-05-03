/*
Sum of all Submatrices

Given a 2D Matrix A of dimensions N*N, we need to return sum of all possible submatrices.


Problem Constraints
1 <= N <=30 0 <= A[i][j] <= 10   


Input Format
Single argument representing a 2-D array A of size N x N.


Output Format
Return an integer denoting the sum of all possible submatrices in the given matrix.


Example Input
A = [ [1, 1]
      [1, 1] ]


Example Output
16


Example Explanation
Number of submatrices with 1 elements = 4, so sum of all such submatrices = 4 * 1 = 4
Number of submatrices with 2 elements = 4, so sum of all such submatrices = 4 * 2 = 8
Number of submatrices with 3 elements = 0
Number of submatrices with 4 elements = 1, so sum of such submatrix = 4
Total Sum = 4+8+4 = 16
*/

//sol->

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    
    int sum=0; 
  
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            int top_left = (i + 1) * (j + 1); 
                                                    // Number of ways to choose from bottom-right elements 
            int bottom_right = (n - i) * (n - j); 
            sum += (top_left * bottom_right * A[i][j]); 
        } 
  
    return sum; 
}
