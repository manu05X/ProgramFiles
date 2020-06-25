/*
Sudoku
Problem Description

Write a program to solve a Sudoku puzzle by filling the empty cells. Empty cells are indicated by the character '.' You may assume that there will be only one unique solution.


https://imgur.com/EK0XKBP.png
A sudoku puzzle,


https://imgur.com/Jj8P4u5.png
and its solution numbers marked in red.



Problem Constraints
1 <= N <= 9


Input Format
First argument is an array of array of characters representing the Sudoku puzzle.

Output Format
Modify the given input to the required answer.


Example Input
Input 1:

A = [[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]


Example Output
Output 1:

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]


Example Explanation
Explanation 1:

Look at the diagrams given in the question.

*/

//sol->


const int N=9;

bool isValid(vector<vector<char>>&A,int row,int col)
{
    char elem=A[row][col];
    
    if(elem-'0'<1 || elem-'0'>9)
        return false;
        
    for(auto p=0;p<N;p++)
    {
        if(A[p][col]==elem && p!=row)
            return false;
        if(A[row][p]==elem && p!=col)
            return false;
    }
    
    int subRow=(row/3)*3;
    int subCol=(col/3)*3;
    
    for(auto i=subRow;i<subRow+3;i++)
    {
        for(auto j=subCol; j<subCol+3;j++)
        {
            if(A[i][j]==elem && (i !=row || j!=col))
                return false;
        }
    }
    return true;
}

bool sudoku(vector<vector<char>> &A,int row,int col)
{
    if(row==9)
        return true;
        
    int nextRow,nextCol;
    if(col==8)
    {
        nextRow=row+1;
        nextCol=0;
    }
    else
    {
        nextRow=row;
        nextCol=col+1;
    }
    
    if(A[row][col]!='.')
    {
        if(!isValid(A,row,col))
            return false;
        return sudoku(A,nextRow,nextCol);
    }
    
    for(auto i=1;i<=N;i++)
    {
        A[row][col]=i+'0';
        if(isValid(A,row,col) && sudoku(A,nextRow,nextCol))
            return true;
    }
    
    A[row][col]='.';
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()!=N || A[0].size()!=N)
        return;
    sudoku(A,0,0);
}






/*
int rowhash[9][9], colhash[9][9], blockhash[3][3][9];

bool solve(vector<vector<char> > &board, int position) {
    if (position >= 9*9) {
        return true;
    }
    int row = position / 9, col = position % 9;
    if (board[row][col] != '.') {
        return solve(board, position + 1);
    }
    for (int num = 0; num < 9; num++) {
        if (rowhash[row][num] != 1 && colhash[col][num] != 1 && blockhash[row / 3][col / 3][num] != 1) {
            // Include num in the solution 
            board[row][col] = '1' + num;
            rowhash[row][num] = 1;
            colhash[col][num] = 1;
            blockhash[row / 3][col / 3][num] = 1;
            if (solve(board, position + 1)) return true;
            // Reset
            board[row][col] = '.';
            rowhash[row][num] = 0;
            colhash[col][num] = 0;
            blockhash[row / 3][col / 3][num] = 0;
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &board) {

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    memset(rowhash, 0, sizeof(rowhash));
    memset(colhash, 0, sizeof(colhash));
    memset(blockhash, 0, sizeof(blockhash));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                rowhash[i][num] = 1;
                colhash[j][num] = 1;
                blockhash[i / 3][j / 3][num] = 1;
            }
        }
    }    
    
    solve(board, 0);
}
----------------------------------

public class Solution {
    
    private int n;
    private ArrayList<ArrayList<Character>> A;
    private HashSet<Character> hashSet;
    
	public void solveSudoku(ArrayList<ArrayList<Character>> A) {
	    
	    n = A.size();
	    this.A = A;
	    hashSet = new HashSet<>();
	    backtrack(0, 0);
	}
	
	
	public boolean backtrack(int row, int col) {
	    
	    if (row == n)
	        return true;
	    
	    char c = A.get(row).get(col);
	    int rr, cc;
	    rr = row;
	    cc = col + 1;
	    
	    if (cc == n) {
	        rr++;
	        cc = 0;
	    }
	    
	    if (c == '.') {
	        
	        for (char ch = '1'; ch <= '9'; ch++) {
	            A.get(row).set(col, ch);
	            
	            if (isValid(row, col)) {
	                boolean status = backtrack(rr, cc);
	                if (status)
	                    return true;
	            }
	            
	            A.get(row).set(col, '.');
	        }
	        
	    } else {
	        return backtrack(rr, cc);
	    }
	    
	    return false;
	}
	
	
	public boolean isValid(int row, int col) {
	    hashSet.clear();
	    char c;
	    
	    for (int i = 0; i < n; i++) {
	        c = A.get(row).get(i);
	        if (hashSet.contains(c))
	            return false;
	        if (c != '.')
    	        hashSet.add(c);
	    }
	    
	    hashSet.clear();
	    
	    for (int i = 0; i < n; i++) {
	        c = A.get(i).get(col);
	        if (hashSet.contains(c))
	            return false;
	        if (c != '.')
    	        hashSet.add(c);
	    }
	    
	    int sRow = (row / 3) * 3;
	    int sCol = (col / 3) * 3;
	    hashSet.clear();
	    
	    for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
	            
	            int rr = sRow + i;
	            int cc = sCol + j;
	            c = A.get(rr).get(cc);
	            
    	        if (hashSet.contains(c))
    	            return false;
    	        if (c != '.')
        	        hashSet.add(c);
	            
	        }
	    }
	    
	    
	    return true;
	    
	}
	
	
}

----------------------------------------------------------------------------
class Solution:
    # @param A : list of list of chars
    # @return nothing
    def solveSudoku(self, board):
        self.solveSudokuRec(board,0,0)
    
    def solveSudokuRec(self, board,row,col):
        if row == 9:
            return True
        if col == 8:
            nextRow = row +1
            nextCol = 0
        else:
            nextRow = row
            nextCol = col+1
        if board[row][col]!='.':
            return self.solveSudokuRec(board,nextRow,nextCol)
        for c in range(1,10):
            if self.canPut(board,str(c),row,col):
                board[row][col] = str(c)
                if self.solveSudokuRec(board,nextRow,nextCol):
                    return True
                board[row][col] = '.'
        return False
    
    def canPut(self, board, char, row, col):
        for i in range(0,9):
            if board[row][i] == char:
                return False
            if board[i][col] == char:
                return False
        rowGroup = (row//3) * 3
        colGroup = (col//3) * 3 
        for i in range(rowGroup, rowGroup+3):
            for j in range(colGroup, colGroup+3):
                if board[i][j] == char:
                    return False
        return True

*/
