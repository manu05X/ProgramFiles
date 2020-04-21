#include <iostream>
using namespace std;

int main() {
	int * p = new int;
	*p = 10;
	cout << *p << endl;

	double *pd = new double;

	char* c = new char;

	int* pa = new int[50];
	int n;
	cout << "Enter num of elements" << endl; 
	cin >> n;

	int* pa2 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> pa2[i];
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	cout << max << endl;
}


/*
Q1>In CPP, dynamic memory allocation is done using ______________ operator.

Correct Answer: new

Q>2	How will you free the memory allocated by following program -
#include <iostream>
using namespace std;    

int main() {
    int *a = new int;
}
option:
		free a;
		delete *a;
		delete a; 
		new a;
Correct Answer: c


Q3>
Correct statement for creating an integer array of size 5, dynamically -
option:
		int *arr[] = new int[5];
		int *arr = new int[5]; 
		int arr = new int[5];
		int *arr[5] = new int;
Answer :b

Q4>
Correct statement for deallocating the array is -
delete [] arr; 
delete arr;
delete *arr;
delete [] *arr;
Correct Answer: a

Q5>On deleting a dynamic memory, if the pointer value is not modified, then the pointer points to?
option:
		NULL
		Other dynamically allocated memory
		The same deleted memory location 
		It points back to location it was initialized with
Correct Answer:c

*/
