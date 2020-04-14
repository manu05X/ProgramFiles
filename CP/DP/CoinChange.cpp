/*
				PROBLEM STATEMENT
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).


*/


#include <bits/stdc++.h>

using namespace std;
int countWaysToMakeChange(int S[], int n, int m){
	int i, j, x, y; 
  
    // We need n+1 rows as the table  
    // is constructed in bottom up 
    // manner using the base case 0 
    // value case (n = 0) 
    int table[n + 1][m]; 
      
    // Fill the enteries for 0 
    // value case (n = 0) 
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
  
    // Fill rest of the table entries  
    // in bottom up manner  
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            // Count of solutions including S[j] 
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
  
            // Count of solutions excluding S[j] 
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            // total count 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	 int numDenominations;
	 cin >> numDenominations;
	 int* denominations = new int[numDenominations];
	 for(int i = 0; i < numDenominations; i++){
	   cin >> denominations[i];
	 }
	 int value;
	 cin >> value;
	 cout << countWaysToMakeChange(denominations, numDenominations, value)<<endl;

	return 0 ; 
}

/*
//#include<bits/stdc++>
int countWaysToMakeChange(int S[], int m, int n){
     int i, j, x, y; 
  
    // We need n+1 rows as the table  
    // is constructed in bottom up 
    // manner using the base case 0 
    // value case (n = 0) 
    int table[n + 1][m]; 
      
    // Fill the enteries for 0 
    // value case (n = 0) 
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
  
    // Fill rest of the table entries  
    // in bottom up manner  
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            // Count of solutions including S[j] 
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
  
            // Count of solutions excluding S[j] 
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            // total count 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 

}

*/
/*
#include <iostream>
using namespace std;

int coin_change(int n, int* d, int numD, int** output) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	if (numD == 0) {
		return 0;
	}
	// to store overlaping subproblem, it is initialize with -1
	if (output[n][numD] > -1) {
		return output[n][numD];
	}
	int first = coin_change(n - d[0], d, numD);
	int second = coin_change(n, d + 1, numD - 1);
	output[n][numD] = first + second;
	return first + second;
}

int main() {
	int d[2] = {1,2};
	// allocate 2d array here, n + 1 * numD + 1
	// put all -1
	cout << coin_change(4, d, 2) << endl;
}
*/
