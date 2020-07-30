/*
Black Shapes
Problem Description

Given character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)



Problem Constraints
1 <= |A|,|A[0]| <= 1000

A[i][j] = 'X' or 'O'



Input Format
The First and only argument is character matrix A.



Output Format
Return a single integer denoting number of black shapes.



Example Input
Input 1:

 A = [ [X, X, X], [X, X, X], [X, X, X] ]
Input 2:

 A = [ [X, O], [O, X] ]


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 All X's belong to single shapes
Explanation 2:

 Both X's belong to different shapes
 
*/


vector<string>v;
void dfs(int i,int j)
{
    if(i>=v.size()||i<0||j>=v[i].size()||j<0)
        return;
    if(v[i][j]!='X')
        return;
        
    v[i][j]='0';
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}

int Solution::black(vector<string> &A) {
    v=A;
    int r=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]=='X')
                dfs(i,j),r++;
        }
    }

    return r;
}

/*
int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int N;
    int M;
    bool is_valid(int x, int y) {
        if(x < 0 || x >= N || y < 0 || y >= M)
                return false;
        return true;
    }

    void bfs(int i, int j, vector<string> &Vec) {
        queue<pair<int, int> > Que;
        Que.push(make_pair(i, j));

        while(!Que.empty()) {
            pair<int, int> P = Que.front();
            Que.pop();
            Vec[P.first][P.second] = 'O';
            for(int i = 0; i < 4; ++i) {
                int x = P.first + dx[i];
                int y = P.second + dy[i];
                if(is_valid(x, y) && Vec[x][y] == 'X') {
                    Que.push(make_pair(x, y));
                }
            }
        }    
    }

    
int Solution::black(vector<string> &A) {
    vector<string> Vec;
    Vec=A;
    N = Vec.size();
        M = Vec[0].size();
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(Vec[i][j] == 'X') {
                    cnt++;
                    bfs(i, j, Vec);
                }
            }
        }
        return cnt;
}
______________________________________
JAVA:
public class Solution {
    private int count = 0;
    private boolean marked[][];
    private int di[] = new int[] {1, -1, 0, 0};
    private int dj[] = new int[] {0, 0, 1, -1};
    private ArrayList<String> A;
    
    public int black(ArrayList<String> A) {
        int m, n;
        
        if (A == null)
            return 0;
        
        m = A.size();
        n = A.get(0).length();
        
        marked = new boolean[m][n];
        count = 0;
        this.A = A;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!marked[i][j] && A.get(i).charAt(j) == 'X') {
                    dfs(i, j, m, n);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    public void dfs(int i, int j, int m, int n) {
        
        marked[i][j] = true;
        
        for (int k = 0; k < 4; k++) {
            
            int ii = i + di[k];
            int jj = j + dj[k];
            
            if (isValid(ii, jj, m, n) && !marked[ii][jj]) {
                dfs(ii, jj, m, n);   
            }
            
        }
    }
    
    public boolean isValid(int i, int j, int m, int n) {
        
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        if (A.get(i).charAt(j) != 'X')
            return false;
        
        return true;
    }
    
    
}
*/