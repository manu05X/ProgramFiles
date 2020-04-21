//Inline and Default Arguments

#include <iostream>
using namespace std;

inline int max(int a, int b) {
	return (a > b)?  a : b;
}

int main() {
	int a, b;
	cin >> a >> b;

	int c = max(a, b);

	int x,y;
	x = 12;
	y = 34;

	int z = max(x, y);
}
/*
Q1>Inline functions are useful when ______
option:
	Function is large with many nested loops
	Function has many static variables
	Function is small and we want to avoid function call overhead. 
	None of the above

Correct Answer:c


Q>2>What is the output of the following program ?
#include<iostream>
using namespace std;

int getValue(int x = 0, int y = 0, int z){  
    return (x + y + z); 
}

int main(){
   cout << getValue(10);
   return 0;
}
Correct Answer: compilation Error


Q3>
Which of the following statement is correct?
option:
		Only one parameter of a function can be a default parameter.
		Minimum one parameter of a function must be a default parameter.
		All the parameters of a function can be default parameters. 
		No parameter of a function can be default.

Correct Answer c

*/
