#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#define li long int

using namespace std;

li n,m,yes;
char board[55][55];
li check[50][50];

void dfs(li i, li j, li i0, li j0)
{
    check[i][j] = 1;
    if(!(i == i0 && j+1 == j0) && j+1<m)
    {
        if(board[i][j] == board[i][j+1])
        {
            if(check[i][j+1])
            {
                yes = 1;
                return;
            }
            dfs(i,j+1,i,j);
        }

        if(yes) return;
    }
    if(yes) return;
    if(!(i+1 == i0 && j == j0) && i+1<n)
    {
        if(board[i+1][j] == board[i][j])
        {
            if(check[i+1][j])
            {
                yes = 1;
                return;
            }
            dfs(i+1,j,i,j);
        }
        if(yes) return;
    }
    if(yes) return;
    if(!(i == i0 && j-1 == j0) && j-1>=0)
    {
        if(board[i][j] == board[i][j-1])
        {
            if(check[i][j-1])
            {
                yes = 1;
                return;
            }
            dfs(i,j-1,i,j);
        }
        if(yes) return;
    }
    if(yes) return;
    if(!(i-1 == i0 && j == j0) && i-1>=0)
    {
        if(board[i][j] == board[i-1][j])
        {
            if(check[i-1][j])
            {
                yes = 1;
                return;
            }
            dfs(i-1,j,i,j);
        }
        if(yes) return;
    }
    if(yes) return;
    check[i][j] = 2;
}

int main()
{
    li i,j;
    char fau[2];

    while(scanf("%ld %ld",&n,&m)==2)
    {
        gets(fau);
        memset(check,0,sizeof(check));
        yes = 0;

        for(i=0;i<n;i++)
        {
            gets(board[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(check[i][j]==0) dfs(i,j,-1,-1);
                if(yes) break;
            }
            if(yes) break;
        }
        if(yes)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}
