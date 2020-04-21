
//Return Subsequences of a String

#include <iostream>
using namespace std;

int subs(string input, string output[]) {
			//if size is empty so length return 1 i.e only "" 
	if (input.empty()) // base case
	{
		output[0] = "";// base case
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}

int main() {
	string input;
	cin >> input;
	string* output = new string[1000];
	int count = subs(input, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
}