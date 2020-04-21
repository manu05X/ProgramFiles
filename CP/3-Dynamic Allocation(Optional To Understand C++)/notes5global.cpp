//Macros and Global Variables

#include <iostream>
using namespace std;

int a;

void g() {
	a++;
	cout << a << endl;
}

void f() {
	cout << a << endl;
	a++;
	g();
}

int main() {
	a = 10;
	f();
	f();
	cout << a << endl;
}

/*
Q1>What is the output of the following program?
#include<iostream>
using namespace std;

int x = 1;

void print(){
    int x = 2;
    {
        int x = 3;
        cout << x << endl;
    }
}
int main(){
    print();
    return 0;
}

Correct Answer: 3

Q>2>What is the output of the following program?
#include <iostream>
using namespace std;

#define MULTIPLY(a, b) a*b

int main(){
    cout << MULTIPLY(2+3, 3+5);
    return 0;
}
Correct Answer: 16
"MULTIPLY(a, b)" will be replaced by "a*b" in code. So, MULTIPLY(2+3, 3+5) will be replaced by 2+3*3+5. 
And according to operator precedence, multiply operator (*) has higher precedence than plus operator (+). 
So, 3*3 will be evaluated first. Hence expression will become : 2+9+5 = 16


Q3>
What is the output of the following program?
#include <iostream>
using namespace std;

#define SQUARE(x) x*x

int main(){
    int x = 36 / SQUARE(6);
    cout << x;

    return 0;
}


Answer :36


*/