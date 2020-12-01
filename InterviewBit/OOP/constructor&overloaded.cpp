// Which is called first constructor or overloaded new operator in C++?

/*
Answer: if we have overloaded new operator in the class then on creation of object dynamically, 
overloaded new operator will be called first and then class constructor will be called.

And reverse is the case for overloaded delete and destructor i.e. destructor will be called first 
then overloaded delete operator in C++ program

Below is the C++ program illustrating overloading of new and delete operators. In this program, 
we have a class Book and this class has constructor Book(), overloaded new and delete operator and a destructor ~Book().

On creation of object of Book class in main () function, first overloaded new function will be called then 
the class constructor.
*/


#include<iostream>
using namespace std;

class Book{
public:
	Book(){
		cout<<"constructor"<<endl;
	}
	//Overloaded new operator
	void* operator new(size_t size){
		cout<<"Overloaded new operator"<<endl;
		return malloc(size); 
	} 
	//overloaded delete operator
	void operator delete(void* ptr){
		cout<<"overloaded delete operator"<<endl;
		free(ptr); 
	} 
	~Book(){
		cout<<"Destructor"<<endl;
	} 
};

int main(){

	//This will call overloaded new function from 
	//class Book, not from OS.
	Book *ob = new Book(); 
	delete ob;

	return 0;
}

/*
OUTPUT:

Overloaded new operator
constructor
Destructor
overloaded delete operator

NOTE:
If we overload new and delete operator in a class, then on creation of object using new, 
memory will not be directly requested from operating system, but class new and delete overloaded 
function will be called in which we write custom memory allocation or request memory to operating system.
*/