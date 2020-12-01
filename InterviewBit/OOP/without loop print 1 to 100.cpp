// Print numbers from 1 to 100 without using loops in C++ code?

//1.Using goto statement:
#include <iostream> 
using namespace std; 

int main() 
{ 
	int i = 0; 
	
begin: 
	i = i + 1; 
	cout << i << " "; 

	if (i < 100) 
	{ 
		goto begin; 
	} 
	return 0; 
} 
//Output: 1 2 3 4 . . . 97 98 99 100


//2.Using recursive main function:
#include <iostream> 
using namespace std; 

int main() 
{ 
	static int i = 1; 
	
	if (i <= 100) 
	{ 
		cout << i++ << " "; 
		main(); 
	} 
	return 0; 
} 
//Output: 1 2 3 4 . . . 97 98 99 100 


/*
Logic is simple to print numbers from 1 to 100 without using loops in C++ code. 
Note that recursion and goto statements are also not allowed.
Logic:

Create a class, let’s say Number, create a static data member variable called num and initialize it with 1.
In class constructor print number and increment variable num by 1;
create an array of 100 objects of the class.
We need to remember two points in C++ programming

First, if we create an object of a class, then its constructor implicitly get called and code block of constructor gets executed.

Secondly, static variable is shared by all objects, so, all the 100 objects will access same static variable.


 
So, if the statement “Number nums[100];”in main function() executed then constructor get called 100 times as there are 100 objects in the array.
Since, all objects are accessing the same static variable, they will understand latest value.Hence, when objs[0] will execute, constructor will get called and 1 will be printed as static variable num is initialized with 1 and num will be incremented by 1.

when objs[1] will execture then again constructor will be called and value 2 will be printed and value will be incremented by 1… and so on, and finally, objs[99] will print 100.

So, number will be printed from 1 to 100.
*/


#include
using namespace std;

//Creat a class number
class Number{
	static int num;
public:
	//Print number in cosntructor
	Number(){
		cout<< num<<endl;
		++num;
	}
};
 //initialize static variable
int Number::num = 1;

int main(){

	//Create array of 100 objects.
	Number objs[100];
	
	return 0;
}