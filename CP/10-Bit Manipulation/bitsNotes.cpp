/*#include <iostream>
using namespace std;

int main(){
    int x = 2;
    x = x << 1;
    cout << x;
}
o/p = 4
*/


#include <iostream>
using namespace std;

int main(){
    int x = -2;
    x = x >> 1;
    cout << x;
}

//o/p = -1


/*
#include <iostream>
using namespace std;

int main(){
    if(~0 == 1) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}
o/p = no
*/

/*
#include <iostream>
using namespace std;

int main(){
    int y = 0;
    if(1 | (y = 1)) {
        cout << "y is " << y;
    }
    else {
        cout << y;
    }
}
o/p = y is 1
*/

/*
#include <iostream>
using namespace std;

int main(){
    int y = 1;
    if(y & (y = 2)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}
o/p = true
*/

// & operator is suitable for turning off a particular bit in a number.
// | operator is suitable for turning on a particular bit in a number.
// ^ operator,& operator,| operator is suitable for checking whether a particular bit is on or off.

