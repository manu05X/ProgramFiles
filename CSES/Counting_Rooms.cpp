#include<bits/stdc++.h>
using namespace std;

char grp[1001][1001];
bool vis[1001][1001];
int N, M;

bool isValid(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M)
        return false;
    if(vis[x][y] == true || grp[x][y] == '#')
        return false;

    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = true;

    if(isValid(x-1, y))
    dfs(x-1, y);

    if(isValid(x , y+1))
    dfs(x , y+1);

    if(isValid(x+1, y))
    dfs(x+1, y);

    if(isValid(x , y-1))
    dfs(x , y-1);
}


int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            cin >> grp[i][j];
    }
    int count = 0;

    for(int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if(grp[i][j] == '.' && vis[i][j] == false)
                dfs(i,j), count++;
        }    
    }

    cout << count<<endl;

    return 0;
}