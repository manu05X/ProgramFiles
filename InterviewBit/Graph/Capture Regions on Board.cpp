/*
Capture Regions on Board
Problem Description

Given a 2-D board A of size N x M containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 1000



Input Format
First and only argument is a N x M character matrix A.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [ 
       [X, X, X, X],
       [X, O, O, X],
       [X, X, O, X],
       [X, O, X, X] 
     ]
Input 2:

 A = [
       [X, O, O],
       [X, O, X],
       [O, O, O]
     ]


Example Output
Output 1:

 After running your function, the board should be:
 A = [
       [X, X, X, X],
       [X, X, X, X],
       [X, X, X, X],
       [X, O, X, X]
     ]
Output 2:

 After running your function, the board should be:
 A = [
       [X, O, O],
       [X, O, X],
       [O, O, O]
     ]


Example Explanation
Explanation 1:

 O in (4,2) is not surrounded by X from below.
Explanation 2:

 No O's are surrounded.
 
*/
bool memo[1002][1002];
vector<vector<char> >v;
int n,c;
void dfs(int i,int j){
    if(memo[i][j])return;
    if(i>=n||i<0||j<0||j>=c)return;
    if(v[i][j]=='X')return;
    memo[i][j]=true;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}
void Solution::solve(vector<vector<char> > &A) {
    memset(memo,0,sizeof(memo));
    n=A.size();
    c=A[0].size();
    v=A;
    for(int i=0;i<c;i++){
        if(A[0][i]!='X')dfs(0,i);
        if(A[n-1][i]!='X')dfs(n-1,i);
    }
    for(int i=0;i<n;i++){
        if(A[i][0]!='X')dfs(i,0);
        if(A[i][c-1]!='X')dfs(i,c-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<c;j++){
            if(!memo[i][j])A[i][j]='X';
        }
    }
}

/*
class Solution {
    public:
        void bfsBoundary(vector<vector<char> >& board, int w, int l) {
            int width = board.size();
            int length = board[0].size();
            deque<pair<int, int> > q;
            q.push_back(make_pair(w, l));
            board[w][l] = 'B';
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop_front();
                pair<int, int> adjs[4] = {
                    {cur.first - 1, cur.second}, 
                    {cur.first + 1, cur.second}, 
                    {cur.first, cur.second - 1},
                    {cur.first, cur.second + 1}
                };
                for (int i = 0; i < 4; ++i) {
                    int adjW = adjs[i].first;
                    int adjL = adjs[i].second;
                    if ((adjW >= 0) && (adjW < width) && (adjL >= 0)
                            && (adjL < length) 
                            && (board[adjW][adjL] == 'O')) {
                        q.push_back(make_pair(adjW, adjL));
                        board[adjW][adjL] = 'B';
                    }
                }
            }
        }

        
         // Use BFS starting from 'O's on the boundary and mark them as 'B', 
         // then iterate over the whole board and mark 'O' as 'X' and 'B' as 'O'.
         
        void solve(vector<vector<char> > &board) {
            int width = board.size();
            if (width == 0) 
                return;
            int length = board[0].size();
            if  (length == 0) 
                return;

            for (int i = 0; i < length; ++i) {
                if (board[0][i] == 'O')
                    bfsBoundary(board, 0, i);

                if (board[width-1][i] == 'O')
                    bfsBoundary(board, width - 1, i);
            }

            for (int i = 0; i < width; ++i) {
                if (board[i][0] == 'O')
                    bfsBoundary(board, i, 0);
                if (board[i][length - 1] == 'O')
                    bfsBoundary(board, i, length - 1);
            }

            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    if (board[i][j] == 'O')
                        board[i][j] = 'X';
                    else if (board[i][j] == 'B')
                        board[i][j] = 'O';
                }
            }
        }
};
-------------
JAVA:

public class Solution {
    
    private boolean [][] marked;
    private int di[] = new int[] {1, -1, 0, 0};
    private int dj[] = new int[] {0, 0, 1, -1};
    private int m, n;
    private ArrayList<ArrayList<Character>> A;
    
	public void solve(ArrayList<ArrayList<Character>> A) {
	    
	    if (A == null)
	        return;
	        
	    m = A.size();
	    n = A.get(0).size();
	    
	    if (m == 0)
	        return;
	        
	    marked = new boolean [m][n];
	    this.A = A;
	    
	    // First and last row
	    for (int i = 0; i < n; i++) {
	        char c = A.get(0).get(i);
	        if (c == 'O')
	            dfs(0, i);
	        c = A.get(m - 1).get(i);
	        if (c == 'O')
	            dfs(m - 1, i);
	    }
	    
	    // First and last column
	    for (int i = 0; i < m; i++) {
	        char c = A.get(i).get(0);
	        if (c == 'O')
	            dfs(i, 0);
	        c = A.get(i).get(n - 1);
	        if (c == 'O')
	            dfs(i, n - 1);
	    }
	    
	    for (int i = 0; i < m; i++) {
	        for (int j = 0; j < n; j++) {
	            if (!marked[i][j])
	                A.get(i).set(j, 'X');
	        }
	    }
	    
	    
	}
	
	public void dfs(int row, int col) {
	    
	    marked[row][col] = true;
	    int nRow, nCol;
	    
	    for (int k = 0; k < 4; k++) {
	        nRow = row + di[k];
	        nCol = col + dj[k];
	        
	        if (isValid(nRow, nCol) && !marked[nRow][nCol] && A.get(nRow).get(nCol) == 'O') {
	            dfs(nRow, nCol);
	        }
	    }
	    
	    
	}
	
	private boolean isValid(int row, int col) {
	    if (row < 0 || row >= m || col < 0 || col >= n)
	        return false;
	        
	    return true;
	}
	
	
}


*/