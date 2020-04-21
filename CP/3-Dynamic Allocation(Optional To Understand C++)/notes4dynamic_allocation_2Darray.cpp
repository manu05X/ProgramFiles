//Dynamic Allocation of 2D Arrays
#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int** p = new int*[m];
	for (int i = 0; i < m; i++) {
		p[i] = new int[i + 1];
		for (int j = 0;j <n; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		delete [] p[i];
	}
	delete [] p;
}


/*
Q1>How to Dynamically create a Two Dimensional Array in C++?
option:
	int *twoDArray = new int[10][10];
	int **twoDArray = new int*[10]; 
	int **twoDArray = new int[10][10];
Correct Answer: b

Q>2>Can we create Jagged Arrays in C++ ?
Correct Answer: Yes


Q3>
Given the following CPP Program. Select the CORRECT Syntax of deleting this 2D array? Check all that apply.
	#include <iostream>
	using namespace std;

	int main()
	{
		int **twoDArray = new int*[10];
		for(int i = 0; i < 10; i++)
			*(twoDArray + i) = new int[10];
	}
Options are -
A. 
	delete twoDArray [][];

B.
	for(int i = 0; i < 10; i++)
		delete twoDArray[i];

C.
	for(int i = 0; i < 10; i++)
		delete [] twoDArray[i];

D.
	for(int i = 0; i < 10; i++)
		delete twoDArray[i][];

Answer :c


*/
