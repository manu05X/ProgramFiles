//Adress Typecasting

#include <iostream>
using namespace std;

int main() {
	int i = 65;
	char c = i;
	cout << c << endl;

	int * p = &i;
	char * pc = (char*)p;

	cout << p << endl;
	cout << pc << endl;

	cout << *p << endl;
	cout << *pc << endl;
	cout << *(pc + 1) << endl;
	cout << *(pc + 2) << endl;
	cout << *(pc + 3) << endl;
}

/*
Q1>Void pointer can point to which type of objects ?
ans: ALL

Q>2	int main()
	{
        int d = 65;
        int i = d;
        char ch = i;
        cout << ch << endl;
	}
Ans: A

Q3>
#include <iostream>
using namespace std;

void updateValue(int *p){
    *p = 610 % 255;
}

int main(){
    char ch = 'A';
    updateValue((int*)&ch);
    cout << ch;
}
Ans: d



*/