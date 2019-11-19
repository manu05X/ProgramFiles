/*
Miser Man
Send Feedback
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.
Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
*/

#include <iostream>
using namespace std;
int a[100][100];
int c[100][100];
int main(){
  int i,j,k,m,n;
  cin>>n>>m;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)
      cin>>a[i][j];
  }
  for(i=0;i<m;i++)
    c[n-1][i]=a[n-1][i];
  for(i=n-2;i>=0;i--){
    c[i][0]=a[i][0]+min(c[i+1][0],c[i+1][1]);
    c[i][m-1]=a[i][m-1]+min(c[i+1][m-1],c[i+1][m-2]);
    for(j=1;j<m-1;j++){
      c[i][j]=a[i][j]+min(c[i+1][j-1],min(c[i+1][j],c[i+1][j+1]));
    }
  }
  k=10000000;
  for(i=0;i<m;i++){
    k=min(k,c[0][i]);
  }
  cout<<k<<endl;
}

