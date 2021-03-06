/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

//BFS solution:

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          grid[r][c] = '0'; // mark as visited
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty()) {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
              neighbors.push({row-1, col}); grid[row-1][col] = '0';
            }
            if (row + 1 < nr && grid[row+1][col] == '1') {
              neighbors.push({row+1, col}); grid[row+1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
              neighbors.push({row, col-1}); grid[row][col-1] = '0';
            }
            if (col + 1 < nc && grid[row][col+1] == '1') {
              neighbors.push({row, col+1}); grid[row][col+1] = '0';
            }
          }
        }
      }
    }

    return num_islands;
  }
};

class Solution 
{
	public:
	int numIslands(vector<vector>& a) 
	{
		int n=a.size(),i,j,ans=0;
		if(!n)
		return 0;
		
		int m=a[0].size();
		queue<pair<int,int>>q;
		vector<vector<int>> vis(n,vector<int> (m));
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='1'&&!vis[i][j])
				{
					q.push({i,j});
					ans++;vis[i][j]=1;
					while(!q.empty())
					{
						int x=q.front().first,y=q.front().second;q.pop();
						if(x+1<n&&a[x+1][y]=='1'&&!vis[x+1][y])
						{
							vis[x+1][y]=1;
							q.push({x+1,y});
						}
						if(x&&a[x-1][y]=='1'&&!vis[x-1][y])
						{
							vis[x-1][y]=1;
							q.push({x-1,y});
						}
						if(y+1<m&&a[x][y+1]=='1'&&!vis[x][y+1])
						{
							vis[x][y+1]=1;
							q.push({x,y+1});
						}
						if(y&&a[x][y-1]=='1'&&!vis[x][y-1])
						{
							vis[x][y-1]=1;
							q.push({x,y-1});
						}
					}
				}
			}
		}return ans;
	}
};
//_____________________________________________________________________________________________________
//DFS solution:

class Solution {
private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r-1][c] == '1') 
		dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r+1][c] == '1') 
		dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c-1] == '1') 
		dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c+1] == '1') 
		dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) 
	{
      for (int c = 0; c < nc; ++c) 
	  {
        if (grid[r][c] == '1') 
		{
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }

    return num_islands;
  }
};

class Solution 
{
	void dfs(int i,int j,vector<vector>& a,vector<vector>& vis)
	{
		int n=a.size(),m=a[0].size();
		if(i==n||j==m||i<0||j<0||a[i][j]=='0')
			return ;
		vis[i][j]=1;
		if(i+1<n&&a[i+1][j]=='1'&&!vis[i+1][j])
			dfs(i+1,j,a,vis);
		if(i&&a[i-1][j]=='1'&&!vis[i-1][j])
			dfs(i-1,j,a,vis);
		if(j+1<m&&a[i][j+1]=='1'&&!vis[i][j+1])
			dfs(i,j+1,a,vis);
		if(j&&a[i][j-1]=='1'&&!vis[i][j-1])
			dfs(i,j-1,a,vis);
	}
		public:
		int numIslands(vector<vector>& a) 
		{
			int n=a.size(),i,j,ans=0;
			if(!n)
			return 0;
			int m=a[0].size();
			vector<vector<int>> vis(n,vector<int> (m));
			for(i=0;i<n;i++)
			{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='1'&&!vis[i][j])
				{
					ans++;
					dfs(i,j,a,vis);
				}
			}
		}
		return ans;
	}
};

// queue solution

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
        return 0;
        int row=grid.size();
        int colm=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<colm;j++)
            {
                if(grid[i][j]=='1')
                {
                     count++;
                    deque<pair<int,int>> q;
                    q.push_back(make_pair(i,j));

                    while(!q.empty())
                    {

                        int first= q.front().first;
                        int second= q.front().second;
                        q.pop_front();
                        if(first-1>=0 && grid[first-1][second]=='1')
                        {
                            q.push_back(make_pair(first-1,second));
                            grid[first-1][second]='0';
                        }
                        if(first+1<row && grid[first+1][second]=='1')
                        {
                            q.push_back(make_pair(first+1,second));
                            grid[first+1][second]='0';
                        }
                        if(second-1>=0 && grid[first][second-1]=='1')
                        {
                            q.push_back(make_pair(first,second-1));
                            grid[first][second-1]='0';
                        }
                        if(second+1<colm && grid[first][second+1]=='1')
                        {
                            q.push_back(make_pair(first,second+1));
                            grid[first][second+1]='0';
                        }
                    } 
                }
            }
        }
            return count;
    }
};

//Java Solution

class Solution {
    public int numIslands(char[][] grid) 
    {
        if (grid.length == 0 || grid[0].length == 0) 
        {
            return 0;
        }
        int m = grid.length, n = grid[0].length;
        int count = 0;
        for (int i = 0; i < m ; i ++) 
        {
            for (int j = 0; j < n; j ++) 
            {
                if (grid[i][j] == '1') 
                {
                    count ++;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return count;
    }
    private void dfs(char[][] grid, int m, int n, int i, int j) 
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') 
        {
            return;
        }
        grid[i][j] = 'X';
        dfs(grid, m, n, i - 1, j);
        dfs(grid, m, n, i + 1, j);
        dfs(grid, m, n, i, j - 1);
        dfs(grid, m, n, i, j + 1);
    }
}