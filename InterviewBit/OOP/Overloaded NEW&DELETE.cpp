//Write simple program to overload new and delete operator in C++?

/*
C++ syntax for overloading new and delete is simple. The new operator will accept object size in 
its parameter and will return a void pointer. The delete operator will accept the pointer do be freed and 
does not return anything, means return void.

Now if we create an object of the class overloaded new and delete operator function will be called 
for memory allocation rather than directly requesting memory to operating system.

*/


#include<iostream>
using namespace std;

class CustomMemory{

public: 

	void* operator new(size_t objectSize);//Overloaded new 
	void operator delete(void* ptr); //Overloaded delete
};

void* CustomMemory::operator new(size_t objectSize)
{
	cout<<"Custom memory allocation"<<endl;
	//May Write costume memory allocation algorithm here
	return malloc(objectSize);

}
void CustomMemory::operator delete(void* ptr)
{
	cout<<"Custom memory de- allocation"<<endl;
	free(ptr);
}


int main(){

	// call overloaded new from the class
	CustomMemory *obj = new CustomMemory();
	// call overloaded delete 
	delete obj;
}
/*
Output:
Custom memory allocation
Custom memory de- allocation
NOTES:

If above question is asked then please don’t forget to mention below points.

Important Points/properties: new and delete operator overloading

Overloaded new operator can accept additional arguments except size to be allocated.
A> In one class delete operator can be overloaded only once.
B> In one class new operator can be overloaded multiple times.
C> When we create object of the class with “new” operator the class overloaded new function will 
	get called with the object size as a parameter. e.g. CustomMemory object = new CustomMemory.
*/

//C++ program example – Overloaded new operator multiple times:

#include<iostream>
using namespace std;


class CustomMemory{
	int i;// size of int is 4 byte 
public:
	CustomMemory(){
		cout<<"Constructor"<<"\n";
	}
	~CustomMemory(){
		cout<<"Destructor"<<"\n";
	}
	//Overloaded new
	void* operator new(size_t objectSize) {
		cout<<"Custom memory allocation"<<"\n";
		//Write allocation algorithm here
		return malloc(objectSize);
	}
	//Overloaded 2 arguments new operator
	void* operator new(size_t objectSize, int x) {
		cout<<"Custom 2 argument memory allocation"<<"\n"; 
		CustomMemory *ptr =(CustomMemory*)malloc(objectSize);
		ptr->i = x;
		return ptr;
	}

	//Overloaded delete 
	void operator delete(void* ptr) {
		cout<<"Custom memory de- allocation"<<"\n";
		free(ptr);
	}
	void Display(){
		cout<<"Value of i ="<<i<<"\n"; 
	} 
};
int main(){

	// call overloaded new from the class
	CustomMemory *obj = new CustomMemory();
	// call overloaded delete
	delete obj;

	//overloaded 2 argument new
	CustomMemory * ptr = new(5)CustomMemory();
	ptr->Display();
	delete ptr;
}

/*
Output:
	Custom memory allocation
	Constructor
	Destructor
	Custom memory de- allocation
	Custom 2 argument memory allocation
	Constructor
	Value of i =5
	Destructor
	Custom memory de- allocation

*/ 

//Which is called first constructor or overloaded new operator in C++?

/*
Interview Question: A C++ class has constructor and overloaded new and delete operator function. 
If we create a class object dynamically using new then out of constructor and overloaded new operator function, 
which one get called first?

Answer: if we have overloaded new operator in the class then on creation of object dynamically, 
overloaded new operator will be called first and then class constructor will be called.

And reverse is the case for overloaded delete and destructor i.e. destructor will be called first 
then overloaded delete operator in C++ program

Below is the C++ program illustrating overloading of new and delete operators. 
In this program, we have a class Book and this class has constructor Book(), overloaded new and delete operator 
and a destructor ~Book().

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
memory will not be directly requested from operating system, but class new and delete overloaded function 
will be called in which we write custom memory allocation or request memory to operating system.
*/
/**/