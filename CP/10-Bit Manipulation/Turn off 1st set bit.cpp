/*
Turn off 1st set bit

You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Integer N 
Output Format :
Updated N
Sample Input 1 :
4
Sample Output 1 :
0
Sample Input 2 :
12 
Sample Output 2 :
8
*/

#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;
	
	cout<< turnOffFirstSetBit(n) <<endl;
		
	return 0;
}


int turnOffFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int m = n&1;
    int count = 0;
    while(!m ){
        m = n&(1<<++count);
    }
    return m^n;
}
