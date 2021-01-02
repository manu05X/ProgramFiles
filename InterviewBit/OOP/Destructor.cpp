/*
Can we overload destructor of a class in C++?

Answer: No, we cannot overload a destructor of a class in C++ programming. Only one empty destructor per class should be there. 
It must have a void parameter list. Destructor in C++ neither takes any parameters nor does it return anything.

So, multiple destructor with different signatures are not possible in a class. Hence, overloading is also not possible.

In below class, if we try to overload destructor for the class A, the compiler will flash an error. For example, 
when we define destructor as ~A(int a) {} , compiler will throw error stating “ a destructor must have a void parameter list”.

*/

//Destructor can't be overlodded sample
#include<bits/stdc++.h>
using namespace std;

class A{
public:
	A(){
		cout<<"constructor...";
	}
	//Destructor
	~A(){
		cout<<"Destructor...";
	}

	//compiler error: : a destructor must have a 'void' parameter list

	~A(int a){
		cout<<"Destructor overloaded...";
	}
};

int main(){
	A o;
	return 0;
}