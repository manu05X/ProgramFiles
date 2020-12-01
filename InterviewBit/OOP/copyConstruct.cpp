// When copy constructor is called in C++? – 3 Scenarios Example

/*
Answer includes multiple scenarios, when copy constructor is called in C++ programs. 
The copy constructor  of a class in C++ is invoked on following scenarios in a C++ program.

Scenario 1: At the time of creating an object, when we initialize it with another existing object of same class type. 
For example, Car obj2= obj1; if a class is Car.

*/


#include <iostream>
using namespace std;

class Car{

public:
	Car(){
		cout << "Car's Constructor\n";
	}

	Car(const Car &ob){ // copy constructor
		cout << "Car's Copy Constructor\n";
	}
};

//TEST
int main()
{		
	Car obj1;//call normal constructor

	Car obj2 = obj1;// call copy constructor 

	return 0;
}


/*
OUTPUT:
Car’s Constructor
Car’s Copy Constructor

Scenario 2: When an object of the same class type is passed by value as a parameter to a function.

Scenario 3: When a function returns an object of that class by value.
 
C++ Program Example : Both scenarios has been depicted in below C++ program example with comments

*/


#include
using namespace std;

class Car{

public:
	Car(){
		cout << "Car's Constructor\n";
	}

	Car(const Car &ob){ // copy constructor
		cout << "Car's Copy Constructor\n";
	}

	//Function that will receive object by value and
	//return object by value.

	Car function(Car ob/*call copy constructor*/){

		//do something...
		
		//When a function returns an object of that class by value.
		return ob;// call copy constructor
	}

};


int main()
{	
	Car obj1;//call normal constructor
	
	//When an object of the same class type is passed by value
	//as a parameter to a function.
	//function returns an object by value
	Car obj2 = obj1.function(obj1);


	return 0;
}

/*
OUTPUT:
Car’s Constructor
Car’s Copy Constructor
Car’s Copy Constructor
 
*/
