//Reference and Pass By Reference

#include <iostream>
using namespace std;

void increment(int& i) {
	i++;
}

// bad practice
int& f(int n) {
	int a = n;
	return a;
}

// bad practice
int* f2() {
	int i = 10;
	return &i;
}

int main() {
	int* p = f2();

	int i;
	i = 10;

	int& k1 = f(i);


	increment(i);
	cout << i << endl;

	int& j = i;

	i++;
	cout << j << endl;
	j++;
	cout << i << endl;

	int k = 100;
	j = k;
	cout << i << endl;
}
/*
Q1>What is the correct syntax of declaring and defining a reference?
option:
	int a = 10; int &b; b = a;
	int a = 10; int &b = a; 
	int a = 10; int b = &a;
	int a = 10; int &b = &a;

Correct Answer b

Q>2	#include <iostream>
using namespace std;

void func(int p){
    cout << p << " ";
}

int main(){
    int i = 10;
    int &p = i;
    func(p++);
    cout << i;
}
Ans: 10 11

Q3>
#include <iostream>
using namespace std;

void func(int i, int& j, int p){
    i++;
    j++;
    p++;
}

int main(){
    int i = 10;
    int j = 6;
    int &p = i;
    func(i, j, p);
    cout << i << " " << j << " " << p;
}
Ans: 10 7 10



*/