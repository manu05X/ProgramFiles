// What is mutable keyword in C++?

/*
Answer: Using mutable keyword in C++ before any data member of a class, data member can be modified 
inside const function in C++.

We know that in const member function in c++ in, a member data cannot be changed. For example, 
in the below class, if we try to modify the carID variable inside the const function, the compiler 
will flash an error on compile time itself.

*/


class Car
{
	int carID;

public:
	Car():carID(123)//initialize car id
	{
	}

	//const function.
	//this function cannot change any data member
	//of the class.
	int getId()const
	{
		this->carID = 456;// Error cannot modify data
		return this->carID;
	}
};

/*
So, If we want to allow modification in constant function in c++ program, we have to use mutable 
keyword before a data member in the class.

Now, the data member is allowed to be modified in cosnt function in C++ program.

*/

class Car
{
	mutable int carID;

public:
	Car():carID(123)//initialize car id
	{	

	}

	int getId()const
	{
		this->carID = 456;//OK, data can be modified.
		return this->carID;
	}
};
int main(){

	Car c;
	cout<<"Car ID ="<< c.getId();

}


/*
Output:456
*/

