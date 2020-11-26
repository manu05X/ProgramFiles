//Video explanation at : https://youtu.be/qsMahidcehY 
//Video explanation at : https://youtu.be/qsMahidcehY 
//Q> Given a class A, we want to know at anytime, how many objects of A live in the "heap" memory.



#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so initialize only once and it will be shared among all objects
    A(){
        x++;
    }
};



int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    cout << A::x << endl;

}

/*
Compilation time: 0.43 sec, absolute service time: 0,66 sec

Error(s):

/tmp/ccuMSIWC.o: In function `main':
source.cpp:(.text.startup+0x6): undefined reference to `A::x'
source.cpp:(.text.startup+0x16): undefined reference to `A::x'
collect2: error: ld returned 1 exit status

*/
//_______________________________________________________________________________________________________________________

#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so initialize only once and it will be shared among all objects
    A(){
        x++;
    }
};

/*
a static variable inside a class should be initialized explicitly by the user using the class name and scope 
resolution operator outside the class 
*/
int A::x = 0; // defining x as it is undefined refrences

int main()
{
    A a, b; //local --> Stored in stack memeory section
    A c, d, e; //local --> Stored in stack memeory section
    
    cout << A::x << endl;

}

/*
Compilation time: 0.43 sec, absolute running time: 0.17 sec, cpu time: 0.01 sec, memory peak: 5 Mb, absolute service time: 0,66 sec

5
*/
//_______________________________________________________________________________________________________________________


#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so its only one and it will be shared among all objects
    A(){
        x++;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    //dynamic --> allocates memory in heap section
    A* ptr = (A*)malloc(sizeof(A)); //malloc only allocates memory, doesnt call constructor  
    
    cout << A::x << endl;

}

/*
// malloc only allocates memory, doesnt call constructor so there is 6 object but output is 5.

5
*/

//_______________________________________________________________________________________________________________________

#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so its only one and it will be shared among all objects
    A(){
        x++;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    //dynamic --> allocates memory in heap section
    //A* ptr = (A*)malloc(sizeof(A)); //malloc only allocates memory, doesnt call constructor
	A* ptr = new A; //call constructor as well as allocates memory in heap
    cout << A::x << endl;
}

/*
// call constructor as well as allocates memory in heap so count of object is 6.

6
*/
//_______________________________________________________________________________________________________________________


#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so its only one and it will be shared among all objects
    A(){
        x++;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    //dynamic --> allocates memory in heap section
    //A* ptr = (A*)malloc(sizeof(A)); //malloc only allocates memory, doesnt call constructor
	A* ptr = new A; //call constructor as well as allocates memory in heap
	
	free(ptr); //doesn't call the destructor only destroy the memeory
    cout << A::x << endl;
}

/*
// doesn't call the destructor only destroy the memeory so count of object is 6 not 5.

6
*/
//_______________________________________________________________________________________________________________________


#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so its only one and it will be shared among all objects
    A(){
        x++;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    //dynamic --> allocates memory in heap section
    //A* ptr = (A*)malloc(sizeof(A)); //malloc only allocates memory, doesnt call constructor
	A* ptr = new A; //call constructor as well as allocates memory in heap
	
	//free(ptr); //doesn't call the destructor only destroy the memeory
	delete ptr; // TO DO: overload delete and decrement counter..
    cout << A::x << endl;
}

/*
// doesn't call the destructor only destroy the memeory so count of object is 6 not 5.

6
*/
//_______________________________________________________________________________________________________________________

#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so its only one and it will be shared among all objects
    A(){
        x++;
    }
	~A(){
       x--;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    //dynamic --> allocates memory in heap section
    //A* ptr = (A*)malloc(sizeof(A)); //malloc only allocates memory, doesnt call constructor
	A* ptr = new A; //call constructor as well as allocates memory in heap
	
	//free(ptr); //doesn't call the destructor only destroy the memeory
	delete ptr; // TO DO: overload delete and decrement counter..
    cout << A::x << endl;
}

/*
// Need to decrement count of x in destructor.

6
*/

//_______________________________________________________________________________________________________________________


#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so its only one and it will be shared among all objects
	//we overload new operator to count object memory allocation in heap
    void* operator new(size_t sz) {
        x++;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    //dynamic --> allocates memory in heap section
    //A* ptr = (A*)malloc(sizeof(A)); //it only allocates memory, doesnt call constructor
    A* ptr = new A; //call constructor as well as allocates memory in heap
    A* ptr2 = new A;
    // free(ptr); //doesn't call the destructor
     //delete ptr; // TO DO: overload delete and decrement counter..
    
    
    cout << A::x << endl;

}

/*
//we overload new operator to count object memory allocation in heap as constructor do not have any idea where memory
// is being allocated in heap or stack. output is 2 becz of ptr and ptr2

2
*/

//_______________________________________________________________________________________________________________________

/*
https://www.geeksforgeeks.org/overloading-new-delete-operator-c/
*/

#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so its only one and it will be shared among all objects
   
    void* operator new(size_t sz) {
        x++;
    }
    void operator delete(void*) {
        x--;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    
    A* ptr = new A; //call constructor as well as allocates memory in heap
     A* ptr2 = new A;

     delete ptr; // TO DO: overload delete and decrement counter..
    
    
    cout << A::x << endl;

}

/*
//we overload delete operator output is 1 as one of object id deleted 

1
*/

//https://www.interviewsansar.com/how-do-you-prevent-heap-allocation-not-stack-for-a-cpp-class/

//Requiring or Prohibiting Heap-based Objects
//https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Requiring_or_Prohibiting_Heap-based_Objects#:~:text=The%20idea%20is%20to%20prevent,a%20protected%20destructor%20as%20below.
/*
You could overload new for A and make it private. This would mean that the compiler would moan... 
unless you're creating an instance of A on the heap from within A. To catch this case, 
you could simply not write A's new method and then the linker would moan about undefined symbols.
*/
#include <iostream>
using namespace std;

class A{
public:
    static int x; // as "x" is "static" so its only one and it will be shared among all objects
private:  
    void* operator new(size_t sz) {
        x++;
    }
    void operator delete(void*) {
        x--;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e; //local --> stack
    
    
    A* ptr = new A; //call constructor as well as allocates memory in heap
     A* ptr2 = new A;

     delete ptr; // TO DO: overload delete and decrement counter..
    
    
    cout << A::x << endl;

}


