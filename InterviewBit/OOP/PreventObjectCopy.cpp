/*
Q > How can you prevent object copy in C++?

Answer:
There is a simple trick that we can apply in C++ class that is by making copy constructor or assignment operator private, 
we can prevent copy or assignment of an object of a class.
In below class Sample we have make copy constructor and assignment operator overloading private. Point to note that we need 
to write empty constructor public as we want to allow object of the class to be created.

So, when we create class objects in main() program and try to call copy constructor e.g. Sample sObj3=sObj1 or assignment 
operator e.g. sObj1=sObj2 etc compiler will throw an error complaining that private members of a class cannot be accessed.

*/

#include<bits/stdc++.h>
using namespace std;


class Sample
{
    private:
        // Make these methods private to prevent access from outside.
        Sample(const Sample&);    //Overloaded Copy constructor
        Sample& operator = (const Sample&);    //Overloaded assignment operator
    public:
        Sample() {} // Make constructor public as we allow users to create object
};
int main()
{
Sample sObj1, sObj2;
sObj1 = sObj2;    //error C2248: 'Sample::operator =' : cannot access private member declared in class 'Sample'  main.cpp 44

return 0;
}