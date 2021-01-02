#include<bits/stdc++.h>
using namespace std;

char grp[1001][1001];
bool vis[1001][1001];
int N, M;

bool isValid(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M)
        return false;
    if(vis[x][y] == true)
        return false;

    return true;
}

/*
void dfs(int x, int y)
{
    vis[x][y] = true;

    cout << x <<" "<< y << endl;
    // checking for up
    if(isValid(x-1, y))
        dfs(x-1, y);
    // checking for right
    if(isValid(x , y+1))
        dfs(x , y+1);
    // checking for down
    if(isValid(x+1, y))
        dfs(x+1, y);
    // checking for left
    if(isValid(x , y-1))
        dfs(x , y-1);
}
*/
//OR

//4 direction to move in cell i.e {up, right, down, left}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    vis[x][y] = true;

    cout << x <<" "<< y << endl;

    // loop the 4 direction to move in grid
    for(int i = 0; i < 4; i++)
    {
        if(isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
    }
}


int main()
{
    cout << "Enter rows AND column :"<<endl;
    cin >> N >> M;
    dfs(1,1);

    return 0;
}