/*
Spiral Order Matrix II
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order. 
 Input Format:
The first and the only argument contains an integer, A.
Output Format:
Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:
1 <= A <= 1000
Examples:
Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
*/

//sol->

vector<vector<int> > Solution::generateMatrix(int A) {
    
    vector<vector<int> >v(A, vector<int>(A));
    int i = 0, j, k = 1;
    
    while(k <= A*A)
    {
        j = i;
        
        while(j < A-i)   //1. horizonal, left to right
        {
            v[i][j++] = k++;
        }
        
        j = i+1;
        while(j < A-i)   //2. vertical, top to bottom
        {
            v[j++][A-i-1] = k++;
        }
        
        j = A-i-2;
        while(j > i)     //3. horizonal, right to left 
        {
            v[A-i-1][j--] = k++;
        }
        
        j = A-i-1;
        while(j > i)     //4. vertical, bottom to  top 
        {
            v[j--][i] = k++;
        }
        
        i++;    // next loop
      
    }
    
    return v;
}
