// Is C++ Empty Constructor necessary to write in a class?

/*
Answer: C++ Empty constructor necessity  depends upon class design requirements. 
We know that C++ class constructor is called when we create an object of a class.

If a class is not required to initialize its data member or does not contain data member, 
there is no need to write empty constructor explicitly. On class object creation, default constructor 
implicitly called will be enough.

In below class, default constructor will be called on object creation of the class.

*/


class A{

public:
	//No constructor, let default constructor called
	void print(){
	}
};
int main(){
	
	A a;
	a.print();	

	return 0;
}

/*
But, in some of the situations we have to write empty constructor in a class. For example,

	*> If we want to overload C++ constructors in the class.
	*> If we want to prevent object creation of a class etc.
	
Note that if we write any constructor in the class, default constructor by the compiler will not be provided and also, 
note that default constructor is an empty constructor.

So, if we want to overload C++ constructors in the class, default constructor will not be available and 
if you want to create an object that call empty constructor, will fail.

For example, in below C++ code example , if we remove empty constructor from the class and create object 
like “Employee obj”, compiler error will be thrown. As it will not find default constructor. Once, 
we write Empty constructor in C++ program, it will be fine

*/

class Employee
{
	int id;	

public:
//Empty Constructor
Employee(){		
	}
	
	//one argument overloaded constructor
	Employee(int id){

		this->id = id;

	}
	
};

/*
Also, if we want to prevent the object creation of the class from outside of the class, 
we can write the empty constructor and make it private using private access specifier in the C++ program.

For example, in below C++ code , if we try to create the object of the class in main program, 
compiler will throw an error.

*/

class A{
private:
	A(){}

public:

	//Constructor NOT REQUIRED
	void print(){
	}
};
int main(){
	
	A a;
	a.print();	

	return 0;
}




/*
What is size of Empty Class in C++ with virtual function?

Answers contains the size of empty class in C++ with virtual function (4 or 8 bytes) and without virtual function 
(1 byte not 0 ) with reason and example.

Answer:

Size of empty class in C++
Size of empty class in C++ is 1 byte and not 0 byte without virtual function, whereas, with virtual function 
size is 4 bytes , whether it is windows or Linux platform etc.

Before explaining the reason for size of an empty class, let’s understand the meaning of empty class in C++ Programming.


 
Empty class means, a class that does not contain any data members e.g. int a , float b and string etc. 
However, a class can contain member functions. In below example, both classes will be called as an empty class.

If we calculate the size of both classes, output will be 1 byte for both.

C++ code example :
*/

//Empty class
class EmptyClass{

}

//Empty class that contains only function
class EmptyClassWithFunctions{

	public void display(){
	}
}
int main(){

	cout << sizeof(EmptyClass)<<endl;
	cout << sizeof(EmptyClassWithFunctions)<<endl;

	return 0;
}

/*
Why size of empty class is 1 byte in C++?
To an object of an empty class, 1 byte is allocated by compiler for unique address identification. 
So, if a class have multiple objects they can have different unique memory location. Suppose, if a class 
does not have any size, what would be stored on the memory location? That’s the reason when we create an 
object of an empty class in C++ program, it needs some memory to get stored, and the minimum amount of memory 
that can be reserved is 1 byte.

So, if we create multiple objects of an empty class, every object will have unique address.
 
Below C++ code example , always give unique address for both objects, created for the class EmptyClass.
*/

int main(){

	EmptyClass obj1;
	EmptyClass obj2;
     
	if (&obj1 == &obj2){
		 cout << "Both object have same address" << endl;
	}else{
		cout << "Both object have unique address" << endl;
	}   	

	return 0;
}

/*
Size of Empty Class in C++ with virtual function :
If an empty class contain virtual function, even though there is no data members in the class, 
its size will not be 1 byte but 4 byte because of virtual pointer i.e. VPTR. Virtual pointer size 
on 32 bit platform is 4 bytes and on 64 bit it is 8 bytes.

Read: What is size of VOID and Char pointer?

When we make a function as a virtual, compiler automatically set a hidden VPTR as a class data member field. 
So, no longer a class is an empty class that contains virtual function in C++.

For example size of below class that contain virtual function will be 4 bytes.

C++ code example :
*/

class ClassWithVirtualFunctions{

public:
	virtual void display(){
	}
};

int main(){

	cout << sizeof(EmptyClassWithFunctions)<<endl;

	return 0;
}

