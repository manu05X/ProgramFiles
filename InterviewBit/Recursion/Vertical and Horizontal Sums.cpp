/*
Vertical and Horizontal Sums
Problem Description

Given a matrix B, of size N x M, you are allowed to do at most A special operations on this grid such that there is no vertical or horizontal contiguous subarray that has a sum greater than C.

A special operation involves multiplying any element by -1 i.e. changing its sign.

Return 1 if it is possible to achieve the answer, otherwise 0.



Problem Constraints
1 <= N, M <= 10

0 <= A <= 5

-105 <= B[i][j], C <= 105



Input Format
The first argument is an integer A, representing the number of special operations allowed.
The second argument has the N x M integer matrix, B.
The third argument is an integer C, as described in the problem statement.



Output Format
Return 1 if it is possible to achieve the answer, otherwise 0.



Example Input
Input 1:

 A = 3
 B = [  
        [1, 1, 1]
        [1, 1, 1]
        [1, 1, 1]
     ]
 C = 2
Input 2:

 A = 1
 B = [
        [1, 1, 1]
        [1, 1, 1]
        [1, 1, 1]
     ]
 C = 2


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 The given matrix does not satisfy the conditions, but if we apply the special operation to B[0][0], B[1][1], B[2][2],
 then the matrix would satisfy the given conditions i.e. no row or column has a sum greater than 2.
Explanation 2:

 It is not possible to apply the special operation 
 to 1 element to satisfy the conditions.

*/

//sol->


vector<vector<int> > grid;
int allowed;
const int NEGINF = -1e9;
bool rec(int ops){
    if(ops == -1){
        return 0;
    }
    int ret = 1;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            int sm = 0;
            for(int k = j; k < grid[0].size(); k++){
                sm += grid[i][k];
                if(sm > allowed){
                    ret = 0;
                    for(int l = j; l <= k; l++){
                        grid[i][l] = -grid[i][l];
                        ret |= rec(ops - 1);
                        grid[i][l] = -grid[i][l];
                    }
                    return ret;
                }
            }
        }
    }
    for(int j = 0; j < grid[0].size(); j++){
        for(int i = 0; i < grid.size(); i++){
            int sm = 0;
            for(int k = i; k < grid.size(); k++){
                sm += grid[k][j];
                if(sm > allowed){
                    ret = 0;
                    for(int l = i; l <= k; l++){
                        grid[l][j] = -grid[l][j];
                        ret |= rec(ops - 1);
                        grid[l][j] = -grid[l][j];
                    }
                    return ret;
                }
            }
        }
    }
    return ret;
}
int Solution::solve(int A, vector<vector<int> > &B, int C) {
    grid = B;
    allowed = C;
    return rec(A);
}







/*
public class Solution {
    
    int a[][], sum;
    int col[], n, m;
    
    boolean check(int u, int v, int op_left, int rsum) {
        if(rsum > sum)  return false;
        if(rsum < 0)    rsum = 0;
        if(v == m) {
            v = 0;  u++;
            rsum = 0;
        }
        if(u == n) {
            for(int x : col) {
                if(x > sum) return false;
            }
            return true;
        }
        if(col[v] > sum)    return false;
        int old = col[v];
        
        col[v] = Math.max(col[v] + a[u][v], 0);
        if(check(u, v+1, op_left, rsum + a[u][v]))
            return true;
        col[v] = old;
        if(op_left > 0) {
            col[v] = Math.max(col[v] - a[u][v], 0);
            if(check(u, v+1, op_left - 1, rsum - a[u][v]))  return true;
            col[v] = old;
        }
        return false;
    }
    
    public int solve(int A, int[][] B, int C) {
        a = B;
        sum = C;
        n = a.length;
        m = a[0].length;
        col = new int[m];
        return check(0, 0, A, 0) ? 1 : 0;
    }
}


----------------------------------

grid = [[]]
allowed = -1
NEGINF = -1e9
def rec(ops):
    global grid 
    global allowed
    if(ops == -1):
        return 0
    
    ret = 1
    
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            sm = 0
            for k in range(j,len(grid[0])):
                sm += grid[i][k]
                if(sm > allowed):
                    ret = 0
                    for l in range(j,k+1):
                        grid[i][l] = -grid[i][l]
                        ret |= rec(ops - 1)
                        grid[i][l] = -grid[i][l]
                    
                    return ret
                    
    for j in range(len(grid[0])):
        for i in range(len(grid)):
            sm = 0
            for k in range(i, len(grid)):
                sm += grid[k][j]
                if(sm > allowed):
                    ret = 0
                    for l in range(i,k+1):
                        grid[l][j] = -grid[l][j]
                        ret |= rec(ops - 1)
                        grid[l][j] = -grid[l][j]
                    return ret
                
    return ret

class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @param C : integer
    # @return an integer
    def solve(self, A, B, C):
        global grid, allowed
        grid = B
        allowed = C
        return rec(A)

*/
