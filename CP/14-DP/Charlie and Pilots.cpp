/*
Charlie and Pilots
Send Feedback
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input
The first line of input contains integer N, 2 = N = 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 = Y < X = 100,000, a salary as a captain (X) and a salary as an assistant (Y).
Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 
*/

#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
    int n,x[10001],y[10001],f[10001][10001];
int main()
{
    //freopen("mpilot.inp","r",stdin);
    //freopen("mpilot.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&x[i],&y[i]);
    f[1][1]=y[1];
    for(int i=2; i<=n; i++)
    {
        f[i][0]=f[i-1][1]+x[i];
        f[i][i]=f[i-1][i-1]+y[i];
        for(int j=1; j<=i-1; j++)
            f[i][j]=min(f[i-1][j-1]+y[i],f[i-1][j+1]+x[i]);
    }
    printf("%d",f[n][0]);
}